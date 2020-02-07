#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>

// special libraries for string_format
#include <stdarg.h>
#include <memory> 

class Grades
{
  private:
    int math;
    int computers;
    int physics;

    // grade bounds
    int max_grade;
    int min_grade;

  public:
    // constructors
    // default (non-parametrized)
    Grades() : math(0), computers(0), physics(0), max_grade(100), min_grade(0) {}
    // parametrized
    Grades(int x, int y, int z) : math(x), computers(y), physics(z), max_grade(100), min_grade(0)  {}
    /** Rule of Three
      * If a class requires a user-defined destructor, 
      * a user-defined copy constructor, or a user-defined copy assignment operator, 
      * it almost certainly requires all three. 
      * */
    // copy constructor
    Grades(const Grades& src);
    // assignment operator
    Grades& operator=(const Grades& rhs);
    // destructor
    ~Grades();
    
    // operators
    void check_bounds(); // prevent operators from going out of bounds
    Grades operator++(); // prefix overload
    Grades operator++(int); // postfix overload
    Grades operator--(); // prefix overload
    Grades operator--(int); // postfix overload
    Grades operator+=(int i);
    Grades operator-=(int i);
    bool operator==(const Grades& rhs);

    // get functions
    int get_math();
    int get_computers();
    int get_physics();

    // print function
    std::string print() const;
}

#endif