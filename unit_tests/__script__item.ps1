g++ -c ../sources/item.cpp -o ../objects/item.obj
g++ -c ../sources/dim2.cpp -o ../objects/dim2.obj
g++ -c ../sources/hash.cpp -o ../objects/hash.obj

g++ item.cpp ../objects/item.obj ../objects/dim2.obj ../objects/hash.obj -std=c++20
if($?)
{
  ./a.exe
  Remove-Item a.exe
}