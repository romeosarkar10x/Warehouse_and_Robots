#include <iostream>
#include <iomanip>
#include "../headers/robot.hpp"


Record::Record(Item _item, Timestamp _pickup_time) :
  item(_item), pickup(_pickup_time) { }

Record::Record(
  Item _item,
  Timestamp _pickup_time,
  Timestamp _delivery_time
) : item(_item), pickup(_pickup_time), delivery(_delivery_time) { }

std::ostream& operator<<(std::ostream& _o, const Record& _record)
{
  _o << _record.item << " @ " << "pickup: " << _record.pickup << ", ";
  _o << "delivery: " << _record.delivery;
  
  return _o;
}

