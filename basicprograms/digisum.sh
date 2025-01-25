#program to find the sum of the digits of a number

echo enter a number 
read n
s=0
while [ $n != 0 ]
do
    d=`expr $n % 10`
    n=`expr $n / 10`
    s=`expr $s + $d`
done
echo sum of digits is $s