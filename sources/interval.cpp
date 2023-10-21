#include "../headers/interval.hpp"
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>

const u_int square__jmptable[] = {0, 1, 4, 9, 16, 25};

void __find(
  std::vector<std::vector<u_int>>& solutions,
  std::vector<u_int>& soln,
  u_int index,
  u_int n,
  u_int sum,
  const u_int sum__
){
  if(sum > sum__ || index >= 6U)
  {
    return;
  }

  if(0 == n)
  {
    if(0 == sum)
    {
      solutions.push_back(soln);
      return;
    }
    return;
  }

  // take
  soln.push_back(index);
  __find(
    solutions,
    soln,
    index,
    n - 1,
    sum - square__jmptable[index],
    sum__
  );
  soln.pop_back();

  // not take
  __find(
    solutions,
    soln,
    index + 1,
    n,
    sum,
    sum__
  );
}

u_int toss(u_int n)
{ // [0, n)
  std::vector<u_int> range(n + 1, 0);
  
  u_int sum = 0;
  for(u_int u = 0; u <= n; u++)
  {
    sum += u;
    range.at(u) = sum;
  }

  u_int random_number = rand() % sum;
  
  u_int rnd = 0;
  while(rnd <= n && range.at(rnd) <= random_number)
  {
    rnd++;
  }

  return rnd - 1;
}

std::vector<u_int> find(u_int n, u_int sum)
{
  std::vector<u_int> soln;
  std::vector<std::vector<u_int>> sols;

  __find(sols, soln, 0U, n, sum, sum);
  
  return sols.at(toss(sols.size()));
}


void __subset_sum_equal_to_k(
  std::vector<std::vector<u_int>>& ans,
  std::vector<u_int>& subset,
  const std::vector<u_int>& vector,
  const u_int k,
  u_int index,
  u_int sum
){

  while(index < vector.size() && 0 == vector.at(index))
  {
    index++;
  }

  if(sum > k)
  {
    return;
  }

  if(index == vector.size())
  {
    if(sum == k)
    {
      ans.push_back(subset);
    }

    return;
  }
  
  // take
  subset.push_back(vector.at(index));
  __subset_sum_equal_to_k(
    ans,
    subset,
    vector,
    k,
    index + 1,
    sum + vector.at(index)
  );
  subset.pop_back();

  // not take
  __subset_sum_equal_to_k(
    ans,
    subset,
    vector,
    k,
    index + 1,
    sum
  );
  return;
}

u_int toss2(u_int n)
{
  if(0 == n)
  {
    return 0;
  }

  return rand() % n;
}

std::vector<u_int> subset_sum_equal_to_k(const std::vector<u_int>& vector, u_int k)
{
  std::vector<u_int> subset;
  std::vector<std::vector<u_int>> ans;

  __subset_sum_equal_to_k(ans, subset, vector, k, 0, 0);

  // for(auto ss : ans)
  // {
  //   std::cout << "subset_sum_equal_to_k: " << ss << std::endl;
  // }

  if(ans.size() == 0)
  {
    return std::vector<u_int>();
  }

  return ans.at(toss2(ans.size()));
}


std::vector<u_int> Interval::generate_random_intervals()
{
  return Interval::generate_random_intervals(Interval::Size, Interval::Mean, Interval::Variance);
}

std::vector<u_int> Interval::generate_random_intervals(
  u_int _n_intervals,
  u_int _mean,
  u_int _variance
){
  if(_variance % 2 != 0)
  { // no solution for odd variance!
    return std::vector<u_int>();
  }

  if(0 == _variance)
  {
    return std::vector<u_int>(_n_intervals, _mean);
  }

  std::vector<u_int> deviations, deviations__subset;
  while(deviations__subset.size() == 0)
  {
    // std::cout << "regenerating deviations!" << std::endl;
    
    deviations = find(_n_intervals, _variance);
    // std::cout << "deviations: " << deviations << std::endl;
    
    deviations__subset = subset_sum_equal_to_k(deviations, std::accumulate(deviations.begin(), deviations.end(), 0) / 2);
    // std::cout << deviations__subset << std::endl;
    // std::cout << "OK" << std::endl;

  }
  
  std::vector<u_int> intervals;
  for(u_int u = 0, v = 0; u < _n_intervals; u++)
  {
    u_int interval = _mean;
    if(v != deviations__subset.size() && deviations.at(u) == deviations__subset.at(v))
    {
      interval += deviations.at(u);
      v++; 
    }
    else
    {
      interval -= deviations.at(u);
    }

    intervals.push_back(interval);
  }
  

  std::shuffle(intervals.begin(), intervals.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
  return intervals;
}

// int main()
// {
//   srand(time(nullptr) + clock());

//   std::cout << "intervals: " << Interval::generate_random_intervals(8, 100, 24) << std::endl;

//   return 0;
// }
