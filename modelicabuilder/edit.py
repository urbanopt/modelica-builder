class Edit:
    start = None
    stop = None
    data = None

    def __lt__(self, other):
        return self.start < other.start

    @staticmethod
    def _get_span(node):
        """get the character start and end of a node

        :param node: object, node to get span
        :return: start, stop, character indices for start and stop of node
        """
        # TODO: handle different node types
        # e.g. if it's a terminal this might not work
        return node.start.start, node.stop.stop

    @classmethod
    def make_delete(cls):
        """Factory for a deletion edit

        :return: function, edit function for delete
        """
        def delete(node):
            start, stop = cls._get_span(node)
            edit = cls()
            edit.start = start
            edit.stop = stop
            edit.data = None
            return edit

        return delete

    @classmethod
    def make_replace(cls, data):
        """Factory for a replacement edit

        :param data: string, replacement value
        :return: function, edit function for replace
        """
        def replace(node):
            start, stop = cls._get_span(node)

            edit = cls()
            edit.start = start
            edit.stop = stop
            edit.data = data
            return edit

        return replace

    @classmethod
    def make_insert(cls, data, insert_after=True):
        """Factory for an insertion edit

        :param data: string, string to insert
        :param insert_after: boolean, if true data is inserted _after_ selected node
        :return: function, edit function for insert
        """
        def insert(node):
            start, stop = cls._get_span(node)
            if insert_after:
                start = stop + 1

            edit = cls()
            edit.start = start
            edit.stop = stop
            edit.data = data
            return edit

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
