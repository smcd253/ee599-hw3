#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <map>
#include <stack>

class Solution {
private:
  char curly[3] = "{}";
  char round[3] = "()";
  char square[3] = "[]";
  std::stack<char> bracket_tracker;
  bool finish_tracking(char* c);
  bool start_tracking(char* c, int i);
public:
  bool valid_brackets(std::string input);
};

#endif