import os
import sys

TEST_DIR = os.path.abspath(os.path.dirname(__file__))
BASE_DIR = os.path.join(TEST_DIR, "..")
SKBUILD_DIR = os.path.join(BASE_DIR, "_skbuild")
# there should be only one directory with the name of the python configuration like linux-x86_64-3.7
PY_CONFIG = os.listdir(SKBUILD_DIR)[0]
SKBUILD_BUILD_DIR = os.path.join(SKBUILD_DIR, PY_CONFIG, "setuptools", "lib")

# prepend path with the build of hdlConvertor
# to use this build version
if sys.path and sys.path[0] != SKBUILD_BUILD_DIR:
    sys.path.insert(1, SKBUILD_BUILD_DIR)
