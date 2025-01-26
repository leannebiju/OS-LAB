#program to find the factorial of a number 

echo enter a number 
read n
if [ $n -ge 0 ]
then 
    if [ $n == 0 ]
    then 
        echo factorial = 1
    else
        f=1
        while [ $n != 1 ]
        do
        f=`expr $n \* $f`
        n=`expr $n - 1`
        done
        echo factorial = $f
    fi
else
    echo finding factorial not possible
fi