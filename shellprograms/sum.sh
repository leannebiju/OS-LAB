echo enter 2 numbers
read a b
c=$((a+b))
echo sum = $c

echo enter a number 
read n
p=$n
s=0
while [ $n != 0 ]
do
    d=$((n%10))
    d=$((d*d*d))
    n=$((n/10))
    s=$((s+d))
done
if [ $s == $p ]
then
    echo Armstrong number 
else 
    echo Not Armstrong number
fi
