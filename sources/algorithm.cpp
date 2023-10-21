#include "../headers/algorithm.hpp"


std::vector<Log> Algorithm::pack(
  const std::vector<Order>& _orders,
  std::priority_queue<Robot, std::vector<Robot>,
  Robot::Compare>* _robots
){
  return std::vector<Log>();
}



std::vector<Log> AlgorithmA::pack(
  const std::vector<Order>& _orders,
  std::priority_queue<Robot, std::vector<Robot>, Robot::Compare>* _robots
){
  std::vector<Log> logs;
  for(const Order& o : _orders)
  {
    Robot r = _robots->top();
    _robots->pop();

    // std::cout << r;
    // auto log = r.deliver(o);
    // std::cout << log << std::endl;
    // logs.push_back(log);
    logs.push_back(r.deliver(o));
    // std::cout << r;

    // std::cout << "### ### ### ### ### ### ### ### ### ### ### ### ### ### ###\n" << std::endl;
    
    _robots->push(r);

    // std::cout << "$$ $$ $$ $$ $$ $$ $$ $$ $$ $$ $$ $$ $$ $$ $$ $$ $$ $$ $$ $$ $$\n" << std::endl;
    // auto xyz = *_robots;
    // while(!xyz.empty())
    // {
    //   std::cout << xyz.top();
    //   xyz.pop();
    // }
    // std::cout << "%% %% %% %% %% %% %% %% %% %% %% %% %% %% %% %% %% %% %% %%\n" << std::endl;
  }

  return logs;
}



std::vector<Log> AlgorithmB::pack(
  const std::vector<Order>& _orders,
  std::priority_queue<Robot, std::vector<Robot>, Robot::Compare>* _robots
){

  std::vector<Log> logs;
  

  return logs;
}


Log AlgorithmB::pack_order(
  const Order& _order,
  std::priority_queue<Robot, std::vector<Robot>, Robot::Compare>* _robots
){
  // Log log(_order, )
  for(auto item : _order.items)
  {
    Robot r = _robots->top();
    _robots->pop();

    r.deliver(_order.generated_time, item, _order.packing_station);
  }
}