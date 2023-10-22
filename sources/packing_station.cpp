#include "../headers/packing_station.hpp"

PackingStation::PackingStation(Dim2 _coordinates) : coordinates(_coordinates) { }

std::vector<PackingStation> PackingStation::generate_random_number_of_packing_stations(Dim2 _warehouse_dimensions)
{
  u_int n_packing_stations = PackingStation::toss(PackingStation::N) + 1;
  
  u_int hash_max = _warehouse_dimensions.x - 1;
  std::vector<u_int> hashes = Hash::generate_random_hashes(n_packing_stations, hash_max);

  return vector__cast<PackingStation>(
    hashes, 
    [] (u_int hash) -> PackingStation
    {
      u_int x = hash + 1;
      u_int y = 0;
      return PackingStation(Dim2(x, y));
    }
  );
}
inline u_int PackingStation::toss(u_int n)
{
  if(0 == n)
  {
    std::cout << "there is an error here : ds3rif" << std::endl;
    return 0;
  }

  return rand() % n;
}

std::ostream& operator<<(std::ostream& _o, PackingStation _packing_station)
{
  _o << "PS(" << _packing_station.coordinates << ")";
  return _o;
}