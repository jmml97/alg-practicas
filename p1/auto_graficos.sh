for archivo in $(find ./datos -type f -follow -print | grep mac);
do
./grafico.sh $archivo
done
