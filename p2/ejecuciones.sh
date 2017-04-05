i=1
MAX=500

while [ $i -lt $MAX ];
do
    echo Valor: $i
    TIMEFORMAT='%R'
    (time ./$1 50 $i > /dev/null) >> $1.dat  2>&1
    ((i += 1))
done

echo ""
