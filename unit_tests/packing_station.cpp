#include <iostream>
#include "../headers/packing_station.hpp"

int main()
{
  srand(time(nullptr) + clock());

  PackingStation ps(Dim2(20, 9)), ps2(Dim2(89, 1));
  std::cout << ps << " ; " << ps2 << std::endl;
  
  std::cout << PackingStation::generate_random_number_of_packing_stations(Dim2(11, 20)) << std::endl;
  return 0;
}