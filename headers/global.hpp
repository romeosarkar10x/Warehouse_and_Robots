#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <vector>
#include <ostream>
#include <ctime>
#include <cstdlib>
// #include <type_traits>

typedef unsigned char u_char;
typedef unsigned int u_int;



class Warehouse;
class Log;
class CSV;
class Order;
class Item;

template<typename T>
std::ostream& operator<<(std::ostream& o, std::vector<T> vector_t)
{
  // static_assert(!std::is_compound_v<T>, "");
  for(auto t : vector_t)
  {
    o << t << " ";
  }

  return o;
}

template<typename _Final, typename _Initial, class _Cast>
std::vector<_Final> vector__cast(const std::vector<_Initial> _vector__initial, _Cast _function__cast)
{
  std::vector<_Final> vector__final;
  
  for(auto __initial : _vector__initial)
  {
    vector__final.push_back(_function__cast(__initial));
  }

  return vector__final;
}

#endif
