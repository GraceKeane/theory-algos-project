#!/bin/bash
# For loop to loop through a list of strings
# in bash

# files="$(ls)"

echo "Testing algorithm on abc.txt"
expec="$(sha512sum abc.txt)"
myout="$(./SHA512 abc.txt)  abc.txt"
echo "Expected: " $expec
echo "Output: " $myout

if [[ $myout == $expec ]]; then
    echo "Pass"
else
    echo "Fail"
fi

echo "Testing algorithm on abc.txt"
expec="$(sha512sum empty.txt)"
myout="$(./SHA512 empty.txt)  empty.txt"
echo "Expected: " $expec
echo "Output: " $myout

if [[ $myout == $expec ]]; then
    echo "Pass"
else
    echo "Fail"
fi