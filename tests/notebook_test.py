
import unittest

from tests.notebook_exec import run_notebook


class NotebookTC(unittest.TestCase):

    def test01_parse_and_dump(self):
        _, errors = run_notebook('../notebooks/01_parse_and_dump.ipynb')
        self.assertEqual(errors, [])


if __name__ == '__main__':
    unittest.main()