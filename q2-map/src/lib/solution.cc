#include "solution.h"

// overload 1
int Solution::add(int a, int b)
{
  int result = a + b;
  // handle overflow
  if (a > 0 && b > 0 && result < 0)
  {
    result = INT32_MAX;
  }
  else if (a < 0 && b < 0 && result > 0)
  {
    result = INT32_MIN;
  }
  
  return result;
}

// overload 2
std::string Solution::add(std::string& a, std::string& b)
{
  std::string result;
  long unsigned int total_size = a.size() + b.size();

  if (total_size <= result.max_size())
  {
    result.append(a);
    result.append(b);
  }
  else
  {
    result.append("invalid: input string(s) too large!");
  }

  return result;
}

// overload 3
std::string Solution::add(std::string& a, int b)
{
  std::string result;
  std::string b_str = std::to_string(b);
  long unsigned int total_size = a.size() + b_str.size();

  if (total_size <= result.max_size())
  {
    result.append(a);
    result.append(b_str);
  }
  else
  {
    result.append("invalid: input string(s) too large!");
  }
  
  return result;
}

// overload 4
std::string Solution::add(int a, std::string& b)
{
  std::string result;
  std::string a_str = std::to_string(a);
  long unsigned int total_size = a_str.size() + b.size();

  if (total_size <= result.max_size())
  {
    result.append(a_str);
    result.append(b);
  }
  else
  {
    result.append("invalid: input string(s) too large!");
  }

  return result;
}
