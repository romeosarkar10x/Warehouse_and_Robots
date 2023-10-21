#include <iostream>
#include <vector>

#include "../headers/warehouse.hpp"


Warehouse::Warehouse(
  Dim2 _dimensions,
  u_int _n_robots,
  Algorithm* _algorithm
) :
  dimensions(_dimensions),
  robots(new std::priority_queue<Robot, std::vector<Robot>, Robot::Compare>()),
  algorithm(_algorithm),
  packing_stations(PackingStation::generate_random_number_of_packing_stations(_dimensions)) {
  for(u_int u = 0; u < _n_robots; u++)
  {
    robots->push(Robot());
  }
}
  

std::vector<Log> Warehouse::pack(const std::vector<Order>& orders)
{
  for(auto& o : orders)
  { // checking!
    if(this->dimensions < o.min_warehouse_dimensions)
    {
      // throw error!
      std::cout << "this order is not compatible with the warehouse dimensions" << std::endl;
      std::cout << this->dimensions << "\n";
      std::cout << o << std::endl;
      std::cout << "gadha ho kya!" << std::endl;
      throw 343;
    }
  }

  return algorithm->pack(orders, robots);
}

void Warehouse::reset()
{
  u_int n_robots = this->robots->size();
  delete robots;

  this->robots = new std::priority_queue<Robot, std::vector<Robot>, Robot::Compare>();
  for(u_int u = 0; u < n_robots; u++)
  {
    this->robots->push(Robot());
  }
  
}

std::vector<Order> Warehouse::generate_random_orders(Timestamp _start_time)
{
  return Order::generate_random_orders(this->dimensions, _start_time, packing_stations);
}


