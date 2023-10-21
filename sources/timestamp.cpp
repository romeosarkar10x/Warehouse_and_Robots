#include <iostream>
#include <string>

#include "../headers/timestamp.hpp"

Timestamp::Timestamp()
{
  this->seconds = (rand() + rand()) % (86400 / 2);
}

Timestamp::Timestamp(u_int _seconds)
{
  this->seconds = _seconds % 86400;
}

// Timestamp::Timestamp(const Timestamp&) = default;
// Timestamp::Timestamp(Timestamp&&) = default;

std::string Timestamp::to_string()
{
  u_int hours = this->seconds / 3600;
  u_int minutes = (this->seconds % 3600) / 60;
  u_int seconds = this->seconds % 60;

  return to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
}

Timestamp Timestamp::operator+(u_int interval)
{
  Timestamp t(*this);
  t.seconds = (t.seconds + interval) % 86400;
  return t;
}

Timestamp Timestamp::operator+=(u_int interval)
{
  this->seconds += interval;
  return *this;
}

bool Timestamp::operator<(const Timestamp& _ts) const
{
  return this->seconds < _ts.seconds;
}
bool Timestamp::operator>(const Timestamp& _ts) const
{
  return this->seconds > _ts.seconds;
}

std::string Timestamp::to_string(u_int x)
{
  u_int length = 0;
  std::string s;
  while(x != 0)
  {
    s += static_cast<char>(x % 10 + '0');
    x /= 10;
    length++;
  }

  while(length < 2)
  {
    s += '0';
    length++;
  }

  {
    auto tmp = s.at(0);
    s.at(0) = s.at(1);
    s.at(1) = tmp;
  }
  
  return s;
}

std::ostream& operator<<(std::ostream& _o, Timestamp _ts)
{
  _o << _ts.to_string();
  return _o;
}