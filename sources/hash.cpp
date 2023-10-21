#include "../headers/hash.hpp"
#include <algorithm>
#include <iostream>

std::vector<u_int> Hash::generate_random_hashes(u_int _n, u_int _hash_max)
{
  if(_n > _hash_max)
  {
    // throw error!
    std::cout << "gadha, this is not possible!" << std::endl;
    throw 234;
  }
  
  std::vector<u_int> hashes;
  for(u_int u = 0; u < _n; u++)
  {
    hashes.push_back(Hash::toss(_hash_max));
    // hashes.push_back(_hash_max - 2);
  }

  std::sort(hashes.begin(), hashes.end());
  { // fixing duplicate hashes
    u_int last_hash = hashes.at(0);
    for(u_int u = 1; u < _n; u++)
    {
      u_int& hash = hashes.at(u);
      if(hash <= last_hash)
      {
        hash = (last_hash + 1) % _hash_max;
      }

      last_hash = std::max(hash, last_hash);
    }
  }

  // repeating the procedure
  std::sort(hashes.begin(), hashes.end());
  { // fixing duplicate hashes
    u_int last_hash = hashes.at(0);
    for(u_int u = 1; u < _n; u++)
    {
      u_int& hash = hashes.at(u);
      if(hash <= last_hash)
      {
        hash = last_hash + 1;
      }

      last_hash = hash;
    }
  }
  
  // std::cout << "hashes: " << hashes << std::endl;
  return hashes;
}


inline u_int Hash::toss(u_int n)
{ // [0, n)
  if(0 == n)
  {
    return 0;
  }

  return rand() % n;
}