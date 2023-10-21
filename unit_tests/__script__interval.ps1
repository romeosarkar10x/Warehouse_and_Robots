g++ -c ../sources/interval.cpp -o ../objects/interval.obj

g++ interval.cpp ../objects/interval.obj
if($?)
{
  ./a.exe
  Remove-Item a.exe
}