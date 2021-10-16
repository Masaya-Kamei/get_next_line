#!/bin/zsh

ESTATUS=0
TEST_FILE=("test_files/*.txt")

# make address
echo "[Address Test]"
make -s address
for T in ${TEST_FILE[@]}; do
	echo ${T}
	diff <(eval "./gnl ${T} 2>&1") <(eval "cat -n ${T} 2>&1")
	ESTATUS=$((ESTATUS|=$?))
done

echo

# make leak
echo "[Leak Test]"
make -s leak
for T in ${TEST_FILE[@]}; do
	echo ${T}
	diff <(eval "./gnl ${T} 2>&1") <(eval "cat -n ${T} 2>&1")
	ESTATUS=$((ESTATUS|=$?))
done

echo

if [ $ESTATUS -eq 0 ]; then
	echo -e "[\e[32mOK\e[m]"
else
	echo -e "[\e[31mKO\e[m]"
fi
exit $ESTATUS
