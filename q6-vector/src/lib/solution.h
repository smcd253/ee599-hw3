#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

class vector_interact
{
  private:
    int current_location;
    std::vector<int> my_vector;

  public:
    // constructors
    vector_interact() : current_location(0), my_vector() {};
    vector_interact(std::vector<int> input) : current_location(0), my_vector(input) {};

    
    // print
    void print_menu(FILE* f);
    void print_result(FILE* f, int usr_in);
};

#endif