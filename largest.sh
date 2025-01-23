#program to find largest of three numbers 
echo enter 3 numbers 
read a b c
if [ $a -gt $b ]
then
    if [ $a -gt $c ]
    then
        echo $a is greatest 
    else
        echo $c is greatest
    fi
elif [ $a -lt $b ] 
then 
    if [ $b -gt $c ]
    then 
        echo $b is greatest
    else 
        echo $c is greatest
    fi
else
    echo all the numbers are equal
fi