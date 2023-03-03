#!/bin/bash

echo "Enter a number:"
read n

e_s=0
o_s=0

for ((i=1; i<=n; i++))
do
  num=$i
  while [ $num -gt 0 ]
  do
    digit=$(( $num % 10 ))
    if [ $(( $digit % 2 )) == 0 ]
    then
      e_s=$(( $e_s + $digit ))
    else
      o_s=$(( $o_s + $digit ))
    fi
    num=$(( $num / 10 ))
  done
done

echo "Sum of even digits: $e_s"
echo "Sum of odd digits: $o_s"