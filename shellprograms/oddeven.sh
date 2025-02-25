#program to display if the entered number is odd or even

echo enter a number 
read a
if [ `expr $a % 2` == 0 ]
then
    echo even
else
    echo odd
fi