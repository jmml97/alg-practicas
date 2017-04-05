i=100
MAX=5000
N=10

while [ $i -lt $MAX ];
do
    echo Valor: $i
    (bin/"$1" ${N} ${i}) >> dat/$1.dat
    ((i += 50))
done

echo ""
