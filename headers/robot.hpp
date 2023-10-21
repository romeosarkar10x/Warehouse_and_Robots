#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "global.hpp"
#include "dim2.hpp"
#include "timestamp.hpp"
#include "item.hpp"
#include "packing_station.hpp"
#include "log.hpp"


class Robot
{
public:

  Dim2 coordinates;
  Timestamp idle_since;
  u_int distance_travelled;
  
  Robot();

  // void reset__o4();
  Record deliver(Timestamp _time, Item _item, PackingStation _packing_station);
  Log deliver(
    Timestamp _time,
    std::vector<Item> _items,
    PackingStation _packing_station
  );
  Log deliver(const Order& o);
  // void set__idle_since(Timestamp _timestamp)
  // {
  //   new (&idle_since) Timestamp(_timestamp);
  // }

  // Robot(const Robot&) = default;
  // Robot(Robot&&) = default;
  
  // no assignment
  // Robot& operator=(const Robot&) = delete;
  // Robot& operator=(Robot&&) = delete;
  
  u_int distance(Dim2 _coordinates);

  class Compare
  {
  public:
    bool operator()(const Robot& ra, const Robot& rb)
    {
      return ra.idle_since > rb.idle_since;
    }

  };
  
private:
  u_int goto_(Dim2 _destination);
  friend std::ostream& operator<<(std::ostream& _o, Robot _robo);
};

std::ostream& operator<<(std::ostream& _o, Robot _robo);

#endif