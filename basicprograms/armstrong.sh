#program to find if a number entered by the user is armstrong or not 

echo enter a number 
read n
p=$n
s=0
while [ $n != 0 ]
do
    d=`expr $n % 10`
    d=`expr $d \* $d \* $d`
    n=`expr $n / 10`
    s=`expr $s + $d`
done
if [ $s == $p ]
then
    echo Armstrong number 
else 
    echo Not Armstrong number
fi