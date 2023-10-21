#include <iostream>

#include "../headers/hash.hpp"

int main()
{
  srand(time(nullptr) + clock());

  std::cout << Hash::generate_random_hashes(5, 23) << std::endl;
  return 0;
}