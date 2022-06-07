"""
****************************************************************************************************
:copyright (c) 2020-2022, Alliance for Sustainable Energy, LLC.
All rights reserved.
****************************************************************************************************
"""


from modelica_builder import modelica_parser


class Edit:
    DELETE = 'delete'
    REPLACE = 'replace'
    INSERT = 'insert'

    def __init__(self, start, stop, data, operation):
        self.start = start
        self.stop = stop
        self.data = data
        self._operation = operation

    def __lt__(self, other):
        """Sort by start then by stop"""
        if self.start != other.start:
            return self.start < other.start

        return self.stop <= other.stop

    def __repr__(self):
        attributes = [f'{attr}={repr(getattr(self, attr))}'
                      for attr in self.__dict__.keys() if not attr.startswith('__')]
        return f'Edit({", ".join(attributes)})'

    @classmethod
    def make_delete(cls):
        """Factory for a deletion edit

        :return: function, edit function for delete
        """
        def delete(node):
            start, stop = modelica_parser.get_span(node)
            return cls(start, stop, None, cls.DELETE)

        return delete

    @classmethod
    def make_replace(cls, data):
        """Factory for a replacement edit

        :param data: string, replacement value
        :return: function, edit function for replace
        """
        def replace(node):
            start, stop = modelica_parser.get_span(node)

            return cls(start, stop, data, cls.REPLACE)

        return replace

    @classmethod
    def make_insert(cls, data, insert_after=True):
        """Factory for an insertion edit

        :param data: string, string to insert
        :param insert_after: boolean, if true data is inserted _after_ selected node
        :return: function, edit function for insert
        """
        def insert(node):
            start, stop = modelica_parser.get_span(node)
            if insert_after:
                start = stop

            # set stop to start, we aren't removing any data
            stop = start
            return cls(start, stop, data, cls.INSERT)

        return insert

    @classmethod
    def apply_edits(cls, edits, document):
        """Sort, fix, and apply the edits to the document

        Raises an exception if it's unable to resolve overlapping edits

        :param edits: list, collection of edits to be applied
        :param document: string, document to apply edits to
        :return: string, edited document
        """
        ordered_edits = cls._sort_and_fix_edits(edits)
        # very inefficient- strings are immutable in Python so we are copying
        # entire document for every edit
        # O(m*n), m = bytes in document, n = number of edits
        for edit in ordered_edits:
            # remove edit span
            if edit.start != edit.stop:
                document = document[:edit.start] + document[edit.stop:]

            # insert data at the start of span
            if edit.data is not None:
                document = document[:edit.start] + \
                    edit.data + \
                    document[edit.start:]

        return document

    @classmethod
    def _sort_and_fix_edits(cls, edits):
        """Sorts edits and tries to remove any overlaps as best as possible
        The result can then be applied in order to data

        :param edits: list, list of edits to sort and fix
        :return: list, edits in sorted order for application
        """
        if not edits:
            return []

        edits.sort()
        fixed_edits = [edits[0]]
        # fix edits by removing or merging overlapping edits
        for current_edit in edits[1:]:
            last_edit = fixed_edits[-1]
            # if non-overlapping, keep both edits
            non_overlapping = last_edit.start < current_edit.start and last_edit.stop <= current_edit.stop
            if non_overlapping:
                fixed_edits.append(current_edit)
                continue

            # if edits have equal spans, priority is based on operation type
            if current_edit.start == last_edit.start and current_edit.stop == last_edit.stop:
                # check if operations are the same
                if current_edit._operation == last_edit._operation:
                    # if both are inserts, keep both edits
                    if current_edit._operation == cls.INSERT:
                        fixed_edits.append(current_edit)
                        continue
                    # else arbitrarily choose the last_edit by dropping the current
                    else:
                        continue

                operations = [
                    current_edit._operation,
                    last_edit._operation
                ]
                # if one is a delete it's retained and the other is dropped
                if cls.DELETE in operations:
                    if current_edit._operation == cls.DELETE:
                        fixed_edits.pop()
                        fixed_edits.append(current_edit)
                    continue
                # if one is a replace it's retained and the other is dropped
                if cls.REPLACE in operations:
                    if current_edit._operation == cls.REPLACE:
                        fixed_edits.pop()
                        fixed_edits.append(current_edit)
                    continue
                # by process of elimination we should have handled all cases by now
                raise Exception(f'Unexpected case comparing edits:\n  Last Edit: {last_edit}\n  Current Edit: {current_edit}')

            # handle cases where one edit 'consumes' the other
            #
            # CASE 1 - last edit consumes current edit (discard current edit)
            # [.....]
            #   [..]
            #
            # CASE 2 - current edit consumes last edit (discard last edit and keep current edit)
            # [..]
            # [.....]
            #
            # CASE 3 - last edit is an INSERT (keep both edits)
            # []
            # [....]
            # Case 1
            if last_edit.start <= current_edit.start and current_edit.stop <= last_edit.stop:
                continue
            # Case 2 or 3
            if current_edit.start == last_edit.start and last_edit.stop <= current_edit.stop:
                # Case 3
                if last_edit._operation == cls.INSERT:
                    fixed_edits.append(current_edit)
                    continue
                # Case 2
                fixed_edits.pop()
                fixed_edits.append(current_edit)
                continue

            # raise an exception if we reach this point as we aren't sure how to handle it yet
            raise Exception(f'Unhandled case for fixing edits:\n  Last Edit: {last_edit}\n  Current Edit: {current_edit}')

        # reverse the result so the edits towards the end of the document are applied first
        # this prevents clobbering the indices
        return reversed(fixed_edits)
