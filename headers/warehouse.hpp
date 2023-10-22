#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include <iostream>
#include <vector>
#include <queue>


#include "global.hpp"
#include "dim2.hpp"
#include "robot.hpp"
#include "algorithm.hpp"
#include "packing_station.hpp"
#include "order.hpp"
#include "log.hpp"



class Warehouse
{
public:
  
  Warehouse(Dim2 _dimensions, u_int _n_robots, Algorithm* _algorithm);
  
  std::vector<Log> pack(const std::vector<Order>& orders);
  void reset();
  std::vector<Order> generate_random_orders(Timestamp _start_time = Timestamp());

private:

public:
  const Dim2 dimensions;
  std::priority_queue<Robot, std::vector<Robot>, Robot::Compare> *robots;
  Algorithm* algorithm;
  std::vector<PackingStation> packing_stations;
  

  
};



#endif