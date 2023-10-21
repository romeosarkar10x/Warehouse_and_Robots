#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include "global.hpp"
#include <iostream>
#include <vector>


class Interval
{
public:
  
  // no objects!
  Interval() = delete;

  static std::vector<u_int> generate_random_intervals();
  static std::vector<u_int> generate_random_intervals(
    u_int _n_intervals,
    u_int _mean,
    u_int _variance
  );

private:
  static const u_int Size = 4;
  static const u_int Mean = 30;
  static const u_int Variance = 24;
};


#endif