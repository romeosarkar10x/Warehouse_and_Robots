#include "../headers/log.hpp"



Log::Log(
  const Order& _order,
  Timestamp _start_time
) : order(_order), start(_start_time) { }


void Log::add_record(Record _record)
{
  records.push_back(_record);
}


size_t Log::size() const
{
  return records.size();
}

Record& Log::at(u_int u)
{
  if(u >= records.size())
  {
    std::cout << "gadha, in function Log::at(), you gave u: " << u << " but n_records is " << records.size() << std::endl;
    throw 1034;
    // throw error!
  }

  return records.at(u);
}


#define SPACES "  "

std::ostream& operator<<(std::ostream& _o, const Log& _log)
{
  _o << "Log(\n";
  _o << SPACES "order_number: " << _log.order.order_number << "generated_time: "
  << _log.order.generated_time << "\n";
  
  _o << SPACES "start: " << _log.start<< "\n";
  _o << SPACES "finish: " << _log.finish << "\n";
  
  _o << SPACES "records: [" << _log.records.size() << "] -> {\n";
  for(auto record : _log.records)
  {
    _o << SPACES SPACES << record << "\n";
  }
  _o << SPACES "}\n";

  _o << ")" << std::endl;
  return _o;
}

#undef SPACES
