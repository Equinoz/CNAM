#!/bin/bash

let "sum = 0"
while [[ $1 != "" ]]
do
	let "sum = $sum + $1"
	shift
done
echo $sum
