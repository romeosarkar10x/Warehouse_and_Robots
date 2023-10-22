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

  // std::cout << orders.size() << std::endl;
  
  
  // algorithmA
  {
    auto logs = w.pack(orders);
    CSV::write_to_file("algorithm_a.csv", logs);
  }

  // algorithmB
  {
    w.reset();
    delete w.algorithm;
    w.algorithm = new AlgorithmB; 
    auto logs = w.pack(orders);
    CSV::write_to_file("algorithm_b.csv", logs);
  }

  return 0;
}