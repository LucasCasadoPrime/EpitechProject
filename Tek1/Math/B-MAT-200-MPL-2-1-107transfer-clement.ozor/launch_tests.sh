#!/bin/bash

echo -e "\e[90m------------[ \e[93mGCC Compilation \e[90m]------------\e[39m"
make re
echo -e "\e[90m-------------[ \e[92mGCC - Success \e[90m]-------------\n\e[39m"

CURRENT_TEST=1
TEST_PASSED=0

echo -e "\e[90m----------------[ \e[93mTest #$CURRENT_TEST \e[90m]----------------\e[39m"
TEST=$(./107transfer)
EXPECTED="Error: arguments count incorrect."
if [ "$TEST" = "$EXPECTED" ]; then
    echo -e "\e[0;32mSuccess: \e[0;37mtest passed successfully.\n"
    CURRENT_TEST=$(( CURRENT_TEST + 1 ))
    TEST_PASSED=$(( TEST_PASSED + 1 ))
else
    echo -e "\e[0;31mError:\e[0;37m $EXPECTED \e[0;31mexpected but\e[0;37m $TEST \e[0;31mreceived.\n"
    CURRENT_TEST=$(( CURRENT_TEST + 1 ))
fi

echo -e "\e[90m----------------[ \e[93m Results \e[90m]----------------\e[39m"
TOTAL=$(( TEST_PASSED * 100 / (CURRENT_TEST - 1) ))
if [ $TOTAL -lt 35 ]; then
    echo -e "\e[0;36mNumbers of tests: \e[0;31m$TEST_PASSED/$(($CURRENT_TEST - 1))"
    echo -e "\e[0;36mPercentage: \e[0;31m$TOTAL%"
elif [ $TOTAL -lt 70 ]; then
    echo -e "\e[0;36mNumbers of tests: \e[0;33m$TEST_PASSED/$(($CURRENT_TEST - 1))"
    echo -e "\e[0;36mPercentage: \e[0;33m$TOTAL%"
else
    echo -e "\e[0;36mNumbers of tests: \e[0;32m$TEST_PASSED/$(($CURRENT_TEST - 1))"
    echo -e "\e[0;36mPercentage: \e[0;32m$TOTAL%"
fi