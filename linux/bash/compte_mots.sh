#!/bin/bash

read input
let "sum = 0"
while [[ $input != "fin" ]]
do
	let "sum = $sum + 1"
	read input
done
echo $sum
