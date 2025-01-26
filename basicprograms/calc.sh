#simple calculator program that performs addition, subtraction, multiplication and division according to user choice

echo enter 2 numbers 
read a b
echo enter your choice 1.addition 2.subtraction 3.multiplication 4.division
read choice 
case $choice in 
1) c=`expr $a + $b`
   ;;
2) c=`expr $a - $b`
   ;;
3) c=`expr $a \* $b`
   ;;   
4) c=`echo "scale=2; $a / $b" | bc`
   ;;
*) echo invalid choice
   ;;
   esac
if [ $choice -gt 0 -a $choice -le 4 ]
then
echo result is $c
fi