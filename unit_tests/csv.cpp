#include <iostream>
#include "../headers/csv.hpp"
#include "../headers/warehouse.hpp"

int main()
{
  const u_int n_robots = 7;

  const u_int length = 15;
  const u_int width = 29;

  const Dim2 dim(length, width);

  Warehouse w(dim, n_robots, new AlgorithmA);
  auto orders = w.generate_random_orders();

  auto logs = w.pack(orders);

  std::cout << logs << std::endl;
  CSV::write_to_file("wh.log", logs);


  return 0;
}