g++ -c ../sources/timestamp.cpp -o ../objects/timestamp.obj
g++ -c ../sources/order.cpp -o ../objects/order.obj
g++ -c ../sources/item.cpp -o ../objects/item.obj
g++ -c ../sources/dim2.cpp -o ../objects/dim2.obj
g++ -c ../sources/interval.cpp -o ../objects/interval.obj
g++ -c ../sources/packing_station.cpp -o ../objects/packing_station.obj
g++ -c ../sources/hash.cpp -o ../objects/hash.obj

g++ order.cpp ../objects/order.obj ../objects/timestamp.obj ../objects/item.obj ../objects/dim2.obj ../objects/interval.obj ../objects/packing_station.obj ../objects/hash.obj
if($?)
{
  ./a.exe
  Remove-Item a.exe
}