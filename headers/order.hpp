#ifndef ORDER_HPP
#define ORDER_HPP

#include <iostream>
#include "global.hpp"
#include "timestamp.hpp"
#include "item.hpp"
#include "packing_station.hpp"
#include "interval.hpp"

class Order
{
public:
  Order(
    Timestamp _generated_time,
    std::vector<Item>&& _items,
    PackingStation _packing_station,
    Dim2 _min_warehouse_dimensions
  );
  
  static std::vector<Order> generate_random_orders(
    Dim2 _warehouse_dimensions,
    Timestamp _start_time,
    const std::vector<PackingStation>& _packing_stations
  );


private:
  friend class Log;
  friend class CSV;
  friend std::ostream& operator<<(std::ostream& _o, const Order& _order);
  friend class Warehouse;
  friend class AlgorithmA;
  friend class AlgorithmB;
  friend class Robot;

  static u_int __order_number;

public:
  u_int order_number;
  Timestamp generated_time;
  std::vector<Item> items;
  PackingStation packing_station;
  Dim2 min_warehouse_dimensions;

  static u_int toss(u_int n);
};

std::ostream& operator<<(std::ostream& _o, const Order& _order);

#endif