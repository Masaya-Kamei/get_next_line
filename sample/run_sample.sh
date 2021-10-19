#!/bin/zsh

GNL_CFILES=(get_next_line.c get_next_line_utils.c)
GNL_INCLUDE_DIR=../
GNL_DIR=../
TEST_FILE=../unit_tests/test_files/1_basic.txt

gcc main.c -I${GNL_INCLUDE_DIR} ${GNL_CFILES[@]/#/${GNL_DIR}/}
echo "---sample---"
./a.out ${TEST_FILE}
