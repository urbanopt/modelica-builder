from modelica_builder import modelica_parser


class Edit:
    def __init__(self, start, stop, data):
        self.start = start
        self.stop = stop
        self.data = data

    def __lt__(self, other):
        return self.start < other.start

    @classmethod
    def make_delete(cls):
        """Factory for a deletion edit

        :return: function, edit function for delete
        """
        def delete(node):
            start, stop = modelica_parser.get_span(node)
            return cls(start, stop, None)

        return delete

    @classmethod
    def make_replace(cls, data):
        """Factory for a replacement edit

        :param data: string, replacement value
        :return: function, edit function for replace
        """
        def replace(node):
            start, stop = modelica_parser.get_span(node)

            return cls(start, stop, data)

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
                start = stop + 1

            # set stop to start, we aren't removing any data
            stop = start
            return cls(start, stop, data)

        return insert

    @staticmethod
    def apply_edits(edits, document):
        """Apply the list of edits in order to the document

        :param edits: list, collection of edits to be applied
        :param document: string, document to apply edits to
        :return: string, edited document
        """
        # very inefficient- strings are immutable in Python so we are copying
        # entire document for every edit
        # O(m*n), m = bytes in document, n = number of edits
        for edit in edits:
            # remove edit span
            if edit.start != edit.stop:
                document = document[:edit.start] + document[edit.stop + 1:]

            # insert data at the start of span
            if edit.data is not None:
                document = document[:edit.start] + \
                    edit.data + \
                    document[edit.start:]

        return document
