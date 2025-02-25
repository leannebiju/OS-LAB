#to find if a year is a leap year or not

echo Enter the year
read y
y1=`expr $y % 100`
y2=`expr $y % 4`

if [ `expr $y % 400` -eq 0 ]
then
    echo $y is a leap year
elif [ $y2 -eq 0 -a $y1 -ne 0 ]
then
    echo $y is a leap year
else
    echo $y is not a leap year
fi 