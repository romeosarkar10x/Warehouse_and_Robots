#include <iostream>
#include <vector>

#include "../headers/item.hpp"

Item::Item(Dim2 _coordinates) :
coordinates(_coordinates) { }

std::vector<Item> Item::generate_random_items(Dim2 _warehouse_dimensions, u_int _n_items)
{
  if(_n_items == UINT_MAX)
  {
    _n_items = Item::toss(std::max(_warehouse_dimensions.x, _warehouse_dimensions.y)) + 2; // make sure there is atleast one item!
    if(_n_items == 0)
    {
      std::cout << "whoa, fatal error: _n_items is 0!!" << std::endl;
    }
  }

  u_int hash_max = _warehouse_dimensions.x * (_warehouse_dimensions.y - 1);
  std::vector<u_int> hashes = Hash::generate_random_hashes(_n_items, hash_max);

  std::vector<Item> items = vector__cast<Item>(
    hashes,
    [=] (u_int hash) -> Item
    {
      u_int x = hash % _warehouse_dimensions.x;
      u_int y = hash / _warehouse_dimensions.x + 1;
      
      return Item(Dim2(x, y));
    }
  );

  return items;
}

const std::string Item::to_string() const
{
  return coordinates.to_string();
}

inline u_int Item::toss(u_int n)
{ // [0, n)
  return rand() % n;
}

std::ostream& operator<<(std::ostream& _o, Item _item)
{
  _o << "Item(" << _item.coordinates << ")";
  return _o;
}