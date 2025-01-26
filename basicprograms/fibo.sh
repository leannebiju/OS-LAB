#program to print the fibonacci series upto n terms
# 0 1 1 2 3 5 8 13 21 34 55 89....

echo "Enter the number of terms"
read n
a=0
b=1
if [ $n -le 0 ]
then 
    echo No series
elif [ $n -eq 1 ]
then
    echo "The fibonacci series upto $n terms is :"
    echo 0
else
    echo "The fibonacci series upto $n terms is :"
    echo 0
    echo 1
    n=`expr $n - 2`
    while [ $n -gt 0 ]
    do
        c=`expr $a + $b`
        echo $c
        a=$b
        b=$c
        n=`expr $n - 1`
    done
fi