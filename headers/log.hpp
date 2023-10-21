#ifndef LOG_HPP
#define LOG_HPP

#include "global.hpp"
#include "record.hpp"
#include "order.hpp"

class Log
{

public:
  const Order& order;
  std::vector<Record> records;
  Timestamp start;
  Timestamp finish;

  Log(const Order& _order, Timestamp _start_time);
  void add_record(Record _record);
  size_t size() const;
  Record& at(u_int u);
};


std::ostream& operator<<(std::ostream& _o, const Log& _log);

#endif