import contextlib
from fnmatch import fnmatch
import os


def find_files(directory, pattern):
    for root, _, files in os.walk(directory):
        for basename in files:
            if fnmatch(basename, pattern):
                filename = os.path.join(root, basename)
                yield filename


def get_file_name(f):
    return os.path.splitext(os.path.basename(f))[0]


class TestFilter():
    """
    Use file to store the filter of the tests and do not execute them again
    """

    def __init__(self, file_name):
        """
        :param file_name: Optional[str]
        :note: if file_name is None the tests are not filtered at all
        """
        self.file_name = file_name
        self.test_filter_set = set()
        if self.file_name is not None and os.path.exists(self.file_name):
            with open(self.file_name) as f:
                self.test_filter_set = set(x for x in f.read().split() if x)

    def dissable_test(self, name):
        with open(self.file_name, "a+") as f:
            f.write(name + "\n")

    def mark_test_as_passed(self, tc):
        if self.file_name is not None:
            testName = tc.id().split(".")[-1]
            self.dissable_test(testName)

    def is_dissabled_test(self, name):
        return name in self.test_filter_set


def generate_test_method_name(file_name, language, existing_prop_dict):
    fn = file_name.replace(".", "_")
    test_name = "test_%s_%s" % (language.name, fn)
    i = 1
    while test_name in existing_prop_dict:
        test_name = "test_%d_%s_%s" % (i, language.name, fn)
        i += 1
    return test_name


@contextlib.contextmanager
def cd(newdir, cleanup=lambda: True):
    prevdir = os.getcwd()
    os.chdir(os.path.expanduser(newdir))

    try:
        yield
    finally:
        os.chdir(prevdir)
        cleanup()

