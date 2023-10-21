#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

#include <iostream>
#include <string>

#include "global.hpp"

class Timestamp
{
public:
  Timestamp();
  Timestamp(u_int _seconds);

  Timestamp(const Timestamp&) = default;
  Timestamp(Timestamp&&) = default;

  std::string to_string();

  Timestamp& operator=(const Timestamp&) = default;
  Timestamp& operator=(Timestamp&&) = default;

  Timestamp operator+(u_int interval);
  Timestamp operator+=(u_int interval);
  
  bool operator<(const Timestamp& _ts) const;
  bool operator>(const Timestamp& _ts) const;

private:
  u_int seconds;
  std::string to_string(u_int x);
};

std::ostream& operator<<(std::ostream& _o, Timestamp _ts);
#endif