#include <iostream>
#include <ctime>
#include <cstdlib>

#include "headers/warehouse.hpp"
#include "headers/csv.hpp"


int main()
{
  srand(time(nullptr));
  const u_int n_robots = 3;

  const u_int length = 15;
  const u_int width = 29;
  const Dim2 dim(length, width);
  
  Warehouse w(dim, n_robots, new AlgorithmA);
  auto orders = w.generate_random_orders();
  auto logs = w.pack(orders);

  CSV::write_to_file("algorithmA.csv", logs);

  return 0;
}