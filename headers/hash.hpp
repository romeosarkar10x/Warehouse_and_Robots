#ifndef HASH_HPP
#define HASH_HPP


#include "global.hpp"
#include <vector>

class Hash
{
public:
  static std::vector<u_int> generate_random_hashes(u_int _n, u_int _hash_max);

private:
  static inline u_int toss(u_int n);

};

#endif