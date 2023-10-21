g++ -c ../sources/dim2.cpp -o ../objects/dim2.obj

g++ dim2.cpp ../objects/dim2.obj
if($?)
{
  ./a.exe
  Remove-Item a.exe
}