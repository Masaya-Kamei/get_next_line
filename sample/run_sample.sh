#!/bin/zsh

GNL_CFILES=(get_next_line.c get_next_line_utils.c)
GNL_INCLUDE_DIR=../
GNL_DIR=../
TEST_FILES=(1_basic.txt 2_noend_nl.txt)
TEST_FILE_DIR=../unit_tests/test_files

gcc main.c -I${GNL_INCLUDE_DIR} ${GNL_CFILES[@]/#/${GNL_DIR}/}
echo "---sample---"
./a.out ${TEST_FILES[@]/#/${TEST_FILE_DIR}/}
