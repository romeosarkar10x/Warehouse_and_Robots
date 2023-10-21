#include <iostream>
#include "../headers/dim2.hpp"

int main()
{
  Dim2 a(0, 5), b(4, 2);
  std::cout << a << " ; " << b << std::endl;
  std::cout << Dim2::manhattan_distance(a, b) << "\n";
  return 0;
}