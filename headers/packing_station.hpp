#ifndef PACKING_STATION_HPP
#define PACKING_STATION_HPP

#include "global.hpp"
#include "dim2.hpp"
#include "hash.hpp"

class PackingStation
{
public:
  const Dim2 coordinates;
  static const u_int Time = 5;

  
  PackingStation(Dim2 _coordinates);
  static std::vector<PackingStation> generate_random_number_of_packing_stations(Dim2 _warehouse_dimensions);

  PackingStation(const PackingStation&) = default;
  PackingStation(PackingStation&&) = default;
  
  // no assignment
  PackingStation& operator=(const PackingStation&) = delete;
  PackingStation& operator=(PackingStation&&) = delete;

private:
  friend std::ostream& operator<<(std::ostream& _o, PackingStation _packing_station);
  static const u_int N = 5;
  static inline u_int toss(u_int n);
  
};


std::ostream& operator<<(std::ostream& _o, PackingStation _packing_station);

#endif