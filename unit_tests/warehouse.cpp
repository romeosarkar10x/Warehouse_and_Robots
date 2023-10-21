#include <iostream>
#include "../headers/warehouse.hpp"

int main()
{
  const u_int n_robots = 3;

  const u_int length = 15;
  const u_int width = 29;
  const Dim2 dim(length, width);
  // std::cout << "❤️" << std::endl;
  // std::cout << "❤️" << std::endl;
  
  Warehouse w(dim, n_robots, new AlgorithmA);
  auto orders = w.generate_random_orders();
  auto logs = w.pack(orders);

  // std::cout << "❤️" << std::endl;

  // std::cout << logs << std::endl;


  return 0;
}