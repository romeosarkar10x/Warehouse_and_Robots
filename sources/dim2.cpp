#include <iostream>
#include "../headers/dim2.hpp"

Dim2::Dim2(u_int _x, u_int _y) : x(_x), y(_y) { }
  
u_int Dim2::manhattan_distance(Dim2 _a, Dim2 _b)
{
  u_int distance = 0;

  if(_a.x > _b.x)
  {
    distance += _a.x - _b.x;
  }
  else
  {
    distance += _b.x - _a.x;
  }

  if(_a.y > _b.y)
  {
    distance += _a.y - _b.y;
  }
  else
  {
    distance += _b.y - _a.y;
  }

  return distance;
}

std::ostream& operator<<(std::ostream& _o, Dim2 dim)
{
  _o << dim.x << ", " << dim.y;
  return _o;
}