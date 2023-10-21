cd $PSScriptRoot

g++ -c ../sources/csv.cpp -o ../objects/csv.obj
g++ -c ../sources/log.cpp -o ../objects/log.obj
g++ -c ../sources/hash.cpp -o ../objects/hash.obj
g++ -c ../sources/item.cpp -o ../objects/item.obj
g++ -c ../sources/dim2.cpp -o ../objects/dim2.obj
g++ -c ../sources/order.cpp -o ../objects/order.obj
g++ -c ../sources/robot.cpp -o ../objects/robot.obj
g++ -c ../sources/record.cpp -o ../objects/record.obj
g++ -c ../sources/interval.cpp -o ../objects/interval.obj
g++ -c ../sources/timestamp.cpp -o ../objects/timestamp.obj
g++ -c ../sources/warehouse.cpp -o ../objects/warehouse.obj
g++ -c ../sources/algorithm.cpp -o ../objects/algorithm.obj
g++ -c ../sources/packing_station.cpp -o ../objects/packing_station.obj





g++ csv.cpp ../objects/csv.obj ../objects/algorithm.obj ../objects/warehouse.obj ../objects/record.obj ../objects/interval.obj ../objects/log.obj ../objects/order.obj ../objects/robot.obj ../objects/timestamp.obj ../objects/hash.obj ../objects/dim2.obj ../objects/item.obj ../objects/packing_station.obj
if($?)
{
  ./a.exe
}