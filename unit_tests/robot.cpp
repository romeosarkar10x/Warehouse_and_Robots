#include <iostream>

#include "../headers/robot.hpp"

int main()
{
  Robot r;
  Timestamp t(40032);
  std::cout << t << std::endl;

  Item i(Dim2(10, 4)), i2(Dim2(2, 5)), i3(Dim2(4, 2));
  PackingStation p(Dim2(2, 3)), p2(Dim2(3, 3)), p3(Dim2(23, 11));

  std::cout << r << std::endl;
  r.deliver(t, i, p);
  std::cout << r << std::endl;
  r.deliver(t, i2, p2);
  std::cout << r << std::endl;
  r.deliver(t, i3, p3);
  std::cout << r << std::endl;
  

  return 0;
}