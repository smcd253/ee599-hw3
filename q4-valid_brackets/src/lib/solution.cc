#include "solution.h"

// Runtime = 4 --> O(1)
bool Solution::start_tracking(char* c, int i)
{
  bool result = true;
  if(*c == this->curly[0])
  {
    this->bracket_tracker.push(this->curly[1]);
  }
  else if (*c == this->round[0])
  {
    this->bracket_tracker.push(this->round[1]);
  }
  else if (*c == this->square[0])
  {
    this->bracket_tracker.push(this->square[1]);
  }
  else if (i == 0)
  {
    result = false;
  }
  return result;
}

// Runtime = 7 --> O(1)
bool Solution::finish_tracking(char* c)
{
  bool result = true;
  if(!this->bracket_tracker.empty())
  {
    if(*c == this->bracket_tracker.top())
    {
      this->bracket_tracker.pop();
      result = true;
    }
    else if(*c == this->curly[1] ||
            *c == this->round[1] ||
            *c == this->square[1])
    {
      result = false;
    }
  }
  return result;
}

// Runtime = 2 + (2 + 4 + 7)n + 3 --> O(n)
bool Solution::valid_brackets(std::string input)
{
  // input validation
  if(input.empty())
  {
    return false;
  }
  
  // analyze
  bool result = true;
  // bracket tracker contains the closing bracket corresponding to
  // the last opening bracket type we saw
  for(int i = 0; i < (int)input.size(); i++)
  {
    // if we are at the last element and the bracket_tracker is empty
    // then we have trailing non-bracket characters --> return false
    if (i == (int)input.size() - 1 && this->bracket_tracker.empty())
    {
      printf("invalid\n");
      return (result = false);
    }
    // if we see an opening bracket, start tracking it
    else if(!(result = start_tracking(&input[i], i)))
    {
      printf("invalid\n");
      return result;
    }
    // if we see a closing bracket, make sure it matches the last opening bracket
    else if(!(result = finish_tracking(&input[i])))
    {
      printf("invalid\n");
      return result;
    }
  }
  if(this->bracket_tracker.size() > 0)
  {
    result = false;
  }
  return result;
}


