#include <iostream>
#include <vector>
#include "../headers/order.hpp"

int main()
{
  srand(time(nullptr) + clock());

  Dim2 dimensions(7, 22);
  
  std::cout << Order::generate_random_orders(dimensions, Timestamp(), PackingStation::generate_random_number_of_packing_stations(dimensions)) << std::endl;
  
  std::cout << "Generated Orders 🙌" << std::endl;

  return 0;
}