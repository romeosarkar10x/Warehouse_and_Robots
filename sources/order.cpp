#include "../headers/order.hpp"


Order::Order(
  Timestamp _generated_time,
  std::vector<Item>&& _items,
  PackingStation _packing_station,
  Dim2 _min_warehouse_dimensions
) :
  generated_time(_generated_time),
  items(std::move(_items)),
  packing_station(_packing_station),
  min_warehouse_dimensions(_min_warehouse_dimensions) {
  order_number = Order::__order_number++;
}

u_int Order::toss(u_int n)
{ // [0, n)
  return rand() % n;
}

std::vector<Order> Order::generate_random_orders(
  Dim2 _warehouse_dimensions,
  Timestamp _start_time,
  const std::vector<PackingStation>& _packing_stations
){
  auto intervals = Interval::generate_random_intervals();
  u_int n_intervals = intervals.size();
  
  // std::cout << "here!" << std::endl;
  
  Timestamp time = _start_time;
  std::vector<Order> orders;

  orders.push_back(
    Order(
      time,
      Item::generate_random_items(_warehouse_dimensions),
      _packing_stations.at(toss(_packing_stations.size())),
      _warehouse_dimensions
    )
  );

  // std::cout << "wait_here!" << std::endl;
  for(u_int u = 0; u < n_intervals; u++)
  {
    // std::cout << "loop " << u << " >> ";
    time += intervals.at(u);
    orders.push_back(
      Order(
        time,
        Item::generate_random_items(_warehouse_dimensions),
        _packing_stations.at(toss(_packing_stations.size())),
        _warehouse_dimensions
      )
    );
    // std::cout << "loop " << u << " || ";
  }

  return orders;
}


u_int Order::__order_number = 1000;

#define SPACES "  "

std::ostream& operator<<(std::ostream& _o, const Order& _order)
{
  _o << "Order(\n";
  _o << SPACES "order_number: " << _order.order_number << "\n";
  _o << SPACES "generated_time: " <<  _order.generated_time << "\n";
  _o << SPACES "min_warehouse_dimensions: " <<  _order.min_warehouse_dimensions << "\n";
  _o << SPACES "packing_station: " << _order.packing_station << "\n";
  _o << SPACES "items: { " << _order.items << "}\n";
  _o << ");" << std::endl;

  return _o;
}

#undef SPACES