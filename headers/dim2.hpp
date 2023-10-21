#ifndef DIM2_HPP
#define DIM2_HPP


#include <iostream>
#include <string>
#include "global.hpp"

class Warehouse;

class Dim2
{
public:
  u_int x;
  u_int y;
  
  Dim2(u_int _x, u_int _y);
  static u_int manhattan_distance(Dim2 _a, Dim2 _b);

  // Dim2(const Dim2&) = default;
  // Dim2(Dim2&&) = default;
  
  // no assignment
  // Dim2& operator=(const Dim2&) = delete;
  // Dim2& operator=(Dim2&&) = delete;
  
  const std::string to_string() const
  { 
    return "(" + std::to_string(x) + " " + std::to_string(y) + ")";
  }

  bool operator<(const Dim2& dim) const
  {
    return (this->x < dim.x) || (this->y < dim.y);
  }
};


std::ostream& operator<<(std::ostream& _o, Dim2 dim);

#endif