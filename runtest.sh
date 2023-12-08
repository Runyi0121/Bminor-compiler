#!/bin/sh

for testfile in ./test/encode/bad*.bminor
do
	if ./bminor --encode $testfile > $testfile.out
	then
		echo "$testfile success (INCORRECT)"
	else
		echo "$testfile failure (as expected)"
	fi
done

for testfile in ./test/encode/good*.bminor
do
	if ./bminor --encode $testfile > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

for testfile in ./test/scan/good*.bminor
do
	if ./bminor --scan $testfile > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

for testfile in ./test/scan/bad*.bminor
do
	if ./bminor --scan $testfile > $testfile.out
	then
		echo "$testfile success (INCORRECT)"
	else
		echo "$testfile failure (as expected)"
	fi
done

for testfile in ./test/parse/bad*.bminor
do
	if ./bminor --parse $testfile > $testfile.out
	then
		echo "$testfile success (INCORRECT)"
	else
		echo "$testfile failure (as expected)"
	fi
done

for testfile in ./test/parse/good*.bminor
do
	if ./bminor --parse $testfile > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

for testfile in ./test/print/good*.bminor
do
	if ./bminor --print $testfile > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

for testfile in ./test/resolve/good*.bminor
do
	if ./bminor --resolve $testfile > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

for testfile in ./test/resolve/bad*.bminor
do
	if ./bminor --resolve $testfile > $testfile.out
	then
		echo "$testfile success (INCORRECT)"
	else
		echo "$testfile failure (as expected)"
	fi
done

for testfile in ./test/typecheck/good*.bminor
do
	if ./bminor --typecheck $testfile > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

for testfile in ./test/typecheck/bad*.bminor
do
	if ./bminor --typecheck $testfile > $testfile.out
	then
		echo "$testfile success (INCORRECT)"
	else
		echo "$testfile failure (as expected)"
	fi
done

for testfile in ./test/codegen/good*.bminor
    do 
        if ./codegen.sh "$testfile" > "$testfile.out" 
        then 
            echo "$testfile success (as expected)"
        else
            echo "$testfile failure (INCORRECT)"
        fi
    done