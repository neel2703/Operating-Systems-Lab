#!/bin/bash
fname=""
while [ fname != "n" ]
do
	read -p "Enter filename: " fname
	if [ -d $fname ]
	then
		echo "Number of files in folder is: " ls $fname | wc -l
	elif [ -s $fname ]
	then 	
		echo "File contents are: "
		cat $fname
		if [ -x $fname ]
		then
			echo "$fname is an executable"
		else
			echo "$fname is not an executable"
		fi
	else
		echo "File/Directory not found"
	fi
done