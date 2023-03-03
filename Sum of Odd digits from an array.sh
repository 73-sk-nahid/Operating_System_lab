#!/bin/bash

array=(1 2 1 2 1)
sum=0
for i in ${array[@]}
do
	#sum=$((sum+i))
	if(( $i % 2 != 0))
	then 
	sum=$((sum+i))
	fi
	
done
echo sum of odd number:$sum