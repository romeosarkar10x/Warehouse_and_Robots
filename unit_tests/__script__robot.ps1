cd $PSScriptRoot
g++ -c ../sources/robot.cpp -o ../objects/robot.obj
g++ -c ../sources/dim2.cpp -o ../objects/dim2.obj
g++ -c ../sources/item.cpp -o ../objects/item.obj
g++ -c ../sources/packing_station.cpp -o ../objects/packing_station.obj
g++ -c ../sources/hash.cpp -o ../objects/hash.obj
g++ -c ../sources/timestamp.cpp -o ../objects/timestamp.obj


g++ robot.cpp ../objects/robot.obj ../objects/timestamp.obj ../objects/hash.obj ../objects/dim2.obj ../objects/item.obj ../objects/packing_station.obj
if($?)
{
  ./a.exe
  Remove-Item a.exe
}