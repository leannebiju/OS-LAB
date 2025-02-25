echo enter a number
read n
c=0
i=1
while [ $i -le $n ]
do 
d=`expr $n % $i`
if [ $d == 0 ]
then 
    c=`expr $c + 1`
fi
i=`expr $i + 1`
done
if [ $c == 2 ]
then 
    echo prime 
else
    echo not prime 
fi