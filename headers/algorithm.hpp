#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <iostream>
#include <utility>
#include <queue>


#include "global.hpp"
#include "timestamp.hpp"
#include "item.hpp"
#include "log.hpp"
#include "robot.hpp"




class Algorithm
{
public:
  virtual std::vector<Log> pack(const std::vector<Order>& _orders, std::priority_queue<Robot, std::vector<Robot>, Robot::Compare>* _robots);
};

class AlgorithmA : public Algorithm
{
public:
  std::vector<Log> pack(
    const std::vector<Order>& _orders,
    std::priority_queue<Robot, std::vector<Robot>, Robot::Compare>* _robots
  );

};

class AlgorithmB : public Algorithm
{
public:
  std::vector<Log> pack(
    const std::vector<Order>& _orders,
    std::priority_queue<Robot, std::vector<Robot>, Robot::Compare>* _robots
  );

private:
  Log pack_order(
    const Order& _order,
    std::priority_queue<Robot, std::vector<Robot>, Robot::Compare>* _robots
  );
};


#endif