import sys
import traceback
from os import path
from pprint import pprint
import unittest
from nose.tools import nottest

TEST_DIR = path.abspath(path.dirname(__file__))
BASE_DIR = path.join(TEST_DIR, "..")
sys.path.insert(1, path.join(BASE_DIR, "dist"))

import hdlConvertor

@nottest
def test_run(test_file, golden_file):
    test_result = hdlConvertor.verilog_pp(
        path.join(TEST_DIR,test_file),
        ['.','..',path.join('sv_pp','src')],
        "sv2012")
    with open(path.join(TEST_DIR,golden_file), 'r') as myfile:
        test_golden = myfile.read()
    myfile.close()
    return test_result,test_golden


class PreprocessorTC(unittest.TestCase):

    def test_2012_p641(self):
        result,ref = test_run(
            path.join('sv_pp','src','2012_p641.txt'),
            path.join('sv_pp','expected','2012_p641.txt')
        )
        self.assertEqual(result,ref)

    def test_2012_p642(self):
        result,ref = test_run(
            path.join('sv_pp','src','2012_p642.txt'),
            path.join('sv_pp','expected','2012_p642.txt')
        )
        self.assertEqual(result,ref)

    def test_2012_p642_2(self):
        result,ref = test_run(
            path.join('sv_pp','src','2012_p642_2.txt'),
            path.join('sv_pp','expected','2012_p642_2.txt')
        )
        self.assertEqual(result,ref)

    def test_2012_p643(self):
        result,ref = test_run(
            path.join('sv_pp','src','2012_p643.txt'),
            path.join('sv_pp','expected','2012_p643.txt')
        )
        self.assertEqual(result,ref)

    def test_2012_p643_2(self):
        result,ref = test_run(
            path.join('sv_pp','src','2012_p643_2.txt'),
            path.join('sv_pp','expected','2012_p643_2.txt')
        )
        self.assertEqual(result,ref)

    def test_2012_p643_3(self):
        result,ref = test_run(
            path.join('sv_pp','src','2012_p643_3.txt'),
            path.join('sv_pp','expected','2012_p643_3.txt')
        )
        self.assertEqual(result,ref)

    def test_2012_p644(self):
        result,ref = test_run(
            path.join('sv_pp','src','2012_p644.txt'),
            path.join('sv_pp','expected','2012_p644.txt')
        )
        self.assertEqual(result,ref)

    def test_2012_p644_2(self):
        with self.assertRaises(hdlConvertor.parseException) as context:
            result = hdlConvertor.verilog_pp(
            path.join(TEST_DIR,'sv_pp','src','2012_p644_2.txt'),
            ['.','..',path.join('sv_pp','src')],
            "sv2012")
        self.assertTrue(
            '/home/mydir/myfile was not found in include directories\n' == \
            context.exception.__str__()
                       )

    def test_2012_p641_il1(self):
        with self.assertRaises(hdlConvertor.parseException) as context:
            hdlConvertor.verilog_pp(
                path.join(TEST_DIR,'sv_pp','src','2012_p641_il1.txt'),
                ['.','..',path.join('sv_pp','src')],
                "sv2012"
            )
        self.assertTrue('Missmatch in number of argument macro declaration D (2) and macro usage (1)' == context.exception.__str__())

    def test_2012_p641_il2(self):
        with self.assertRaises(hdlConvertor.parseException) as context:
            hdlConvertor.verilog_pp(
                path.join(TEST_DIR,'sv_pp','src','2012_p641_il2.txt'),
                ['.','..',path.join('sv_pp','src')],
                "sv2012"
            )
        self.assertTrue('Missmatch in number of argument macro declaration D (2) and macro usage (0)' == context.exception.__str__())

    def test_2012_p641_il3(self):
        with self.assertRaises(hdlConvertor.parseException) as context:
            hdlConvertor.verilog_pp(
                path.join(TEST_DIR,'sv_pp','src','2012_p641_il3.txt'),
                ['.','..',path.join('sv_pp','src')],
                "sv2012"
            )
        self.assertTrue('Missmatch in number of argument macro declaration D (2) and macro usage (3)' == context.exception.__str__())


    def test_2012_p642_il1(self):
        with self.assertRaises(hdlConvertor.parseException) as context:
            result = hdlConvertor.verilog_pp(
                path.join(TEST_DIR,'sv_pp','src','2012_p642_il1.txt'),
                ['.','..',path.join('sv_pp','src')],
                "sv2012"
            )
        self.assertTrue('Missmatch in number of argument macro declaration MACRO1 (3) and macro usage (2)' == context.exception.__str__())

    #`MACRO3 must have parentesis according to the SV specification.
    #Currently the code is not able to detect this issue
    @unittest.expectedFailure
    def test_2012_p642_il2(self):
        with self.assertRaises(hdlConvertor.parseException) as context:
            result = hdlConvertor.verilog_pp(
                path.join(TEST_DIR,'sv_pp','src','2012_p642_il2.txt'),
                ['.','..',path.join('sv_pp','src')],
                "sv2012"
            )
        self.assertTrue('Missmatch in number of argument macro declaration (3) and macro usage (0)' == context.exception.__str__())

    #No check that string are not split
    @unittest.expectedFailure
    def test_2012_p642_il3(self):
        with self.assertRaises(hdlConvertor.parseException) as context:
            result = hdlConvertor.verilog_pp(
                path.join(TEST_DIR,'sv_pp','src','2012_p642_il3.txt'),
                ['.','..',path.join('sv_pp','src')],
                "sv2012"
            )
        self.assertTrue('an error message' == context.exception.__str__())

        

    def test_FILE_LINE(self):
        test_result = hdlConvertor.verilog_pp(
            path.join(path.dirname(__file__),
                      'sv_pp','src','test_FILE_LINE.sv'
                     ),
        ['.','..',path.join('sv_pp','src')],
        "sv2012")
        test_golden = "module tb();\n\ninitial\n\t$display(\"Internal error: null handle at %s, line %d.\",\n"
        test_golden += "\"" + path.join(path.dirname(__file__),
                      'sv_pp','src','test_FILE_LINE.sv'
                     )+"\", 5);\n\n\nendmodule\n"
        self.assertEqual(test_result,test_golden)


class PreprocessorGrammar(unittest.TestCase):
    '''
    Non regression of grammar.
    '''

    def test_celldefine(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_comments(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_default_nettype(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_define1(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_define2(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_define3(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_define4(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_define5(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_define6(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_define7(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_define8(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_define9(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_define10(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_define11(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_define12(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_define13(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_ifdef(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_ifdef1(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_ifdef2(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_ifdef3(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_ifndef1(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_include(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        with self.assertRaises(hdlConvertor.parseException) as context:
            hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")
        #print ('|'+context.exception.__str__()+'|')
        self.assertTrue('file1.txt was not found in include directories\n' == context.exception.__str__())

    def test_keywords1(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_keywords2(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_line_directive(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_pragma1(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_pragma2(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_real1(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_real2(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_timingspec(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_token1(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        with self.assertRaises(hdlConvertor.parseException) as context:
            hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")
        self.assertTrue('uvm_info is not defined' == context.exception.__str__())

    def test_token2(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        with self.assertRaises(hdlConvertor.parseException) as context:
            hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")
        self.assertTrue('uvm_info is not defined' == context.exception.__str__())

    def test_token3(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        with self.assertRaises(hdlConvertor.parseException) as context:
            hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")
        self.assertTrue('D is not defined' == context.exception.__str__())

    def test_token4(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        with self.assertRaises(hdlConvertor.parseException) as context:
            hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")
        self.assertTrue('D is not defined' == context.exception.__str__())

    def test_token5(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        with self.assertRaises(hdlConvertor.parseException) as context:
            hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")
        self.assertTrue('D is not defined' == context.exception.__str__())

    def test_token6(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        with self.assertRaises(hdlConvertor.parseException) as context:
            hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")
        self.assertTrue('D is not defined' == context.exception.__str__())

    def test_token7(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        with self.assertRaises(hdlConvertor.parseException) as context:
            hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")
        self.assertTrue('wordsize is not defined' == context.exception.__str__())

    def test_token8(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        with self.assertRaises(hdlConvertor.parseException) as context:
            hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

        self.assertTrue('sum is not defined' == context.exception.__str__())

    def test_unconnected_drive(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")

    def test_undef(self):
        test_name = traceback.extract_stack(None, 2)[1][-2]
        hdlConvertor.verilog_pp(path.join(path.dirname(__file__),'sv_pp','raw',test_name+'.txt'),['.','..',path.join('sv_pp','raw')],"sv2012")



if __name__ == "__main__":
    unittest.main()
