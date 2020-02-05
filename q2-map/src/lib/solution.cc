#include "solution.h"

// total runtime = O(3 + n*log(n) + n^2) --> O(n^2)
std::vector<int> Solution::fit_sum(std::vector<int> v, int sum)
{
  // input validation
  if(v.empty() || 
    v.size() > v.max_size() ||
    v.size() < 0) // handle int overflow
  {
    printf("input invalid\n");
    return {};
  }
  printf("v.size = %d\n", v.size());
  printf("v.max_size() = %d\n", v.max_size());

  // result to return
  std::vector<int> result = {};

  // create map out of v vector for log(n) lookup time
  std::map<int,int> val_map;
  // ***** total runtime = O(n*log(n)) (where n = v.size()) *****
  for(int i = 0; i < (int)v.size(); i++) // O(n)
  {
    val_map.insert(std::pair<int,int>(v[i], i)); // O(log(n))
  }

  // loop through map key set to see if we can fit the given sum
  // ***** total runtime = O(n^2) *****
  for (auto n : val_map) // O(n)
  {
    for(auto m : val_map) // O(n)
    {
      if(n.first + m.first == sum) // O(1)
      {
        result.push_back(n.second); // O(1)
        result.push_back(m.second); // O(1)
        return result;
      }
    }
  }
  // if we have found nothing, return an empty array
  return result;
}


