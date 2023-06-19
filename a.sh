#1/bin/bash
echo "enter the number :"
read n
 r=`expr $n % 2`
if [$r -eq 0 ]
echo "$r even"
