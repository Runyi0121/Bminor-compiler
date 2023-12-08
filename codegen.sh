#! /bin/sh

FILE=$1

if ./bminor --codegen $FILE program.s ; then 
    if gcc -g program.s ./src/library.c -o program ; then
        ./program
        echo "output: $?"
        exit 0
    else
        echo "failure on gcc"
    fi
else 
    echo "program failed"
fi
exit 1
