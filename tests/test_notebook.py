#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import unittest

from tests.notebook_exec import run_notebook


ROOT = os.path.join(os.path.dirname(__file__), "..")


class NotebookTC(unittest.TestCase):

    def test01_parse_and_dump(self):
        f = os.path.join(ROOT, 'notebooks', '01_parse_and_dump.ipynb')
        _, errors = run_notebook(f)
        self.assertEqual(errors, [])


if __name__ == '__main__':
    unittest.main()
