#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <vector>
#include <algorithm>

#include "global.hpp"
#include "dim2.hpp"
#include "hash.hpp"

class Item
{
public:
  const Dim2 coordinates;

  Item(Dim2 _coordinates);
  static std::vector<Item> generate_random_items(
    Dim2 _warehouse_dimensions,
    u_int _n_items = UINT_MAX
  );

  Item(const Item&) = default;
  Item(Item&&) = default;

  // no assignment
  Item& operator=(const Item&) = delete;
  Item& operator=(Item&&) = delete;

  const std::string to_string() const;

private:
  static inline u_int toss(u_int n);
};

std::ostream& operator<<(std::ostream& o, Item item);


#endif