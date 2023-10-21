g++ -c ../sources/hash.cpp -o ../objects/hash.obj

g++ hash.cpp ../objects/hash.obj
if($?)
{
  ./a.exe
  Remove-Item a.exe
}