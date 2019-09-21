import unittest

from hdlConvertor import HdlConvertor
from hdlConvertor.language import Language
from tests.file_utils import generate_test_method_name, TestFilter, \
    get_file_name


class ExternTestSpec():
    """
    Container of informations about test
    """

    def __init__(self, main_file, language, preproc_defs, include_dirs, should_fail):
        self.main_file = main_file
        self.language = language
        assert isinstance(language, Language), language
        self.preproc_defs = preproc_defs
        assert isinstance(preproc_defs, dict), preproc_defs
        self.include_dirs = include_dirs
        assert isinstance(include_dirs, list), include_dirs
        self.should_fail = should_fail
        assert isinstance(should_fail, bool), should_fail
        self.debug = False

    def generate_test_method_name(self, existing_prop_dict):
        fn = get_file_name(self.main_file)
        return generate_test_method_name(fn, self.language, existing_prop_dict)
    
    def register_test_on_tc(self, test_filter, tc_property_dict):
        test_name = self.generate_test_method_name(tc_property_dict)
        if not test_filter.is_dissabled_test(test_name):
            tc_property_dict[test_name] = gen_test(self, test_filter)


def gen_test(test_spec, test_filter):
    """
    :type test_spec: ExternTestSpec
    """

    def test(self):
        c = HdlConvertor()
        c.preproc_macro_db.update(test_spec.preproc_defs)
        
        try:
            c.parse([test_spec.main_file, ], test_spec.language,
                    test_spec.include_dirs, debug=test_spec.debug)
        except Exception:
            if test_spec.should_fail:
                # [TODO] some expected erros in this test suite are not related to synatax
                #        need to check maually if the error really means syntax error and
                #        if this library is raising it correctly
                pass
            else:
                raise

        test_filter.mark_test_as_passed(self)

    return test


def generate_external_testcase_class(testcase_class_name, test_configs, SUCESSFULL_TEST_FILTER_FILE):

    # https://stackoverflow.com/questions/32899/how-do-you-generate-dynamic-parameterized-unit-tests-in-python
    class TestsuiteMeta(type):
    
        def __new__(cls, name, bases, _dict):
            test_filter = TestFilter(SUCESSFULL_TEST_FILTER_FILE)
    
            for test_spec in sorted(test_configs, key=lambda x: x.main_file):
                test_spec.register_test_on_tc(test_filter, _dict)
    
            return type.__new__(cls, name, bases, _dict)
    
    # https://www.oipapio.com/question-219175 , python2/3 compatible specification of metatype for class
    return TestsuiteMeta(testcase_class_name, (unittest.TestCase,), {})
