g++ -c ../sources/dim2.cpp -o ../objects/dim2.obj
g++ -c ../sources/packing_station.cpp -o ../objects/packing_station.obj
g++ -c ../sources/hash.cpp -o ../objects/hash.obj

g++ packing_station.cpp ../objects/dim2.obj ../objects/packing_station.obj ../objects/hash.obj
if($?)
{
  ./a.exe
  Remove-Item a.exe
}