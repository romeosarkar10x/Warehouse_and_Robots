#include <iostream>
#include "../headers/item.hpp"

int main()
{
  srand(time(nullptr) + clock());
  
  Item i(Dim2(2, 4)), i2(Dim2(5, 88));
  std::cout << i << " ; " << i2 << std::endl;

  std::cout << Item::generate_random_items(Dim2(22, 59)) << std::endl;
  
  return 0;
}