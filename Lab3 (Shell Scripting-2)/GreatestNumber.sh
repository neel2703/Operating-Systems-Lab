#!/bin/bash
read -p "Enter three numbers: " n1 n2 n3
greatest=0
if [ $n1 -gt $n2 -a $n1 -gt $n3 ]
then
        greatest=$n1
elif [ $n2 -gt $n1 -a $n2 -gt $n3 ]
then
        greatest=$n2
elif [ $n3 -gt $n1 -a $n3 -gt $n2 ]
then
        greatest=$n3
fi
echo "The largest number is: $greatest"