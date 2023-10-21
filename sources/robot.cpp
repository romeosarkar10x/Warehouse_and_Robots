#include <iostream>

#include "../headers/robot.hpp"


Robot::Robot() : coordinates(0, 0), idle_since(0), distance_travelled(0) { };


// void Robot::reset()
// { // Wow!!
//   new (&coordinates) Dim2(0, 0);
// }



u_int Robot::goto_(Dim2 _destination)
{
  u_int distance = Dim2::manhattan_distance(this->coordinates, _destination);
  this->distance_travelled += distance;
  this->coordinates = _destination;

  return distance;
}

Record Robot::deliver(Timestamp _time, Item _item, PackingStation _packing_station)
{
  this->idle_since = std::max(_time, this->idle_since);
  this->idle_since += this->goto_(_item.coordinates);

  Record record(_item, this->idle_since);

  this->idle_since += this->goto_(_packing_station.coordinates);
  
  record.delivery = this->idle_since;
  this->idle_since += PackingStation::Time;
  return record;
}


// Log Robot::deliver(Timestamp _time, std::vector<Item> _items, PackingStation _packing_station)
// {
//   Log log();
//   // Timestamp pickup = 
//   // Timestamp delivery = 
// }


Log Robot::deliver(const Order& _o)
{
  this->idle_since = std::max(_o.generated_time, this->idle_since);
  Log log(_o, this->idle_since);
  
  for(auto item : _o.items)
  { // picking up all items
    u_int initial_distance_travelled = this->distance_travelled;
    this->goto_(item.coordinates);

    this->idle_since += this->distance_travelled - initial_distance_travelled;
    log.add_record(Record(item, this->idle_since));
  }

  { // delivering all the items to the packing station
    u_int initial_distance_travelled = this->distance_travelled;
    this->goto_(_o.packing_station.coordinates);
    
    this->idle_since += this->distance_travelled - initial_distance_travelled; 
  }

  this->idle_since += PackingStation::Time * _o.items.size();

  for(u_int u = 0; u < _o.items.size(); u++)
  {
    log.at(u).delivery = this->idle_since;
  }

  log.finish = this->idle_since;
  return log;
}

u_int Robot::distance(Dim2 _coordinates)
{
  return Dim2::manhattan_distance(coordinates, _coordinates);
}

#define SPACE "  "
std::ostream& operator<<(std::ostream& _o, Robot _robo)
{
  _o << "Robot(\n";
  _o << SPACE "coordinates: (" << _robo.coordinates << ")\n";
  _o << SPACE "idle_since: " << _robo.idle_since << "\n";
  _o << SPACE "distance_travelled: " << _robo.distance_travelled << "\n";
  _o << ")" << std::endl;

  return _o;
}

#undef SPACE