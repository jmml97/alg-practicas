for archivo in $(find ./datos -type f -follow -print);
do
./grafico.sh $archivo
done
