#!/bin/bash

int15() {
	echo "Arrêt refusé"
}

int18() {
	echo "Niques toi"
}

trap "int15" 15
trap "int18" 18
echo $$
while true
do
	echo A
	sleep 1
done
