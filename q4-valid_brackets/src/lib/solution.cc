#include "solution.h"

// Runtime = 3 --> O(1)
void Solution::start_tracking(char* c, int i)
{
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

// Runtime = 2 + (1 + 3 + 7)n + 3 --> O(n)
bool Solution::valid_brackets(std::string input)
{  
  // analyze
  bool result = true;
  // bracket tracker contains the closing bracket corresponding to
  // the last opening bracket type we saw
  for(int i = 0; i < (int)input.size(); i++)
  {
    // if we see an opening bracket, start tracking it
    start_tracking(&input[i], i);
    // if we see a closing bracket, make sure it matches the last opening bracket
    // else the input is invalid, break loop and proceed with reporting and cleanup
    if(!(result = finish_tracking(&input[i])))
    {
      break;
    }
  }
  // if there are any remaining unclosed brackets, return false
  if(this->bracket_tracker.size() > 0)
  {
    result = false;

    // clear stack
    while(!this->bracket_tracker.empty())
    {
      this->bracket_tracker.pop();
    }
  }

  return result;
}


