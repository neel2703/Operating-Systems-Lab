#!/bin/bash
read -p "Enter a number: " num
sum=0
while [ $num -gt 0 ]
do
        temp=$(($num % 10))
        sum=$(($temp + $sum))
        num=$(($no / 10))
done
echo "Sum of digits is: $sum"