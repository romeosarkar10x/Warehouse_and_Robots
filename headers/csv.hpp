#ifndef CSV_HPP
#define CSV_HPP

#include <iostream>
#include <fstream>
#include <vector>

#include "global.hpp"
#include "item.hpp"
#include "timestamp.hpp"
#include "log.hpp"
#include "record.hpp"

class CSV
{
  CSV() = delete;
  // CSV(const Log& log) : string()
  // {
  //   u_int size = log.size();
    
  //   for(u_int u = 0; u < size; u++)
  //   {
  //     Record record = log.at(u);
      
  //     string += std::to_string(log.order.order_number) + ", ";
  //     string += record.item.to_string() + ", ";
  //     string += record.pickup_start_time.to_string() + ", ";
  //     string += record.pickup_finish_time.to_string() + "\n";
  //   }
  // }

private:
  static void write_to_file(std::ofstream& _fout, const Log& _l);

public:
  static void write_to_file(std::string _file_name, const std::vector<Log>& _logs);
};


#endif