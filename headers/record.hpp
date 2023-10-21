#ifndef RECORD_HPP
#define RECORD_HPP

#include "global.hpp"
#include "item.hpp"
#include "timestamp.hpp"

class Record
{
public:
  Item item;
  Timestamp pickup;
  Timestamp delivery;

  Record(Item _item, Timestamp _pickup_time);
  Record(
    Item _item,
    Timestamp _pickup_time,
    Timestamp _delivery_time
  );

};

std::ostream& operator<<(std::ostream& _o, const Record& _record);

#endif