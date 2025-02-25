#program to find if a number entered by the user is armstrong or not 
#i.e. sum of digit^no of digits of a number 
#eg. 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
#9 = 9^1 = 9
#this program is only for three digit numbers 

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