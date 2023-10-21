#include <fstream>
#include "../headers/csv.hpp"
#include "../headers/log.hpp"


void CSV::write_to_file(std::ofstream& _fout, const Log& _l)
{
  for(Record record : _l.records)
  {
    _fout << _l.order.order_number << ", ";
    _fout << _l.order.generated_time << ", ";
    _fout << record.item.to_string() << ", ";
    _fout << record.pickup << ", ";
    _fout << record.delivery << "\n";
  }
}


void CSV::write_to_file(std::string _file_name, const std::vector<Log>& _logs)
{
  std::ofstream fout(_file_name);
  
  fout << "order_number, generated_time, item, time_pickup, time_delivery\n";
  for(auto log : _logs)
  {
    CSV::write_to_file(fout, log);
  }
}



