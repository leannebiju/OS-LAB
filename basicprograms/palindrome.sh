#program to find if the number is palindrome or not
#palindrome number is one that reads the same both ways 
#eg. 121 on reversing also remains 121

echo enter a number 
read n
p=$n
nn=0
while [ $n != 0 ]
do
    d=`expr $n % 10`
    n=`expr $n / 10`
    nn=`expr $nn \* 10 + $d`
done
if [ $p == $nn ]
then 
    echo Palindrome
else 
    echo Not Palindrome
fi