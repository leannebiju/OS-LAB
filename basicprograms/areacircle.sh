#program to find the area of a circle

echo enter radius 
read r
a=`echo 3.14 *\ $r *\ $r | bc`
#bc to do floating point operations
echo area = $a