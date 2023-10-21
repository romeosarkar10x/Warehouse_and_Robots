#include <iostream>
#include <ctime>

#include "../headers/log.hpp"
#include "../headers/robot.hpp"


int main()
{
  srand(clock() + time(nullptr));
  Dim2 dim(12, 17);
  
  auto order = Order::generate_random_orders(dim, Timestamp(34288), PackingStation::generate_random_number_of_packing_stations(dim)).at(0);
  
  std::cout << order << std::endl;

  Robot r;
  std::cout << r << std::endl;
  
  auto log = r.deliver(order);

  std::cout << log << std::endl;

  return 0;
}