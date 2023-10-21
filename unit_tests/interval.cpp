#include <iostream>
#include "../headers/interval.hpp"

int main()
{
  srand(time(nullptr) + clock());
  
  std::cout << Interval::generate_random_intervals(8, 100, 26) << std::endl;
  return 0;
}