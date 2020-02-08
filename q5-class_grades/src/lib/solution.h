#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>

// special libraries for string_format
#include <stdarg.h>
#include <memory> 

class AcademicRecord
{
  private:
    // grade bounds
    int max_grade;
    int min_grade;

  public:
    // member variables
    int math;
    int computers;
    int physics;

    // constructors
    // default (non-parametrized)
    AcademicRecord() : math(0), computers(0), physics(0), max_grade(100), min_grade(0) {}
    // parametrized
    AcademicRecord(int x, int y, int z) : math(x), computers(y), physics(z), max_grade(100), min_grade(0)  {}
    /** Rule of Three
      * If a class requires a user-defined destructor, 
      * a user-defined copy constructor, or a user-defined copy assignment operator, 
      * it almost certainly requires all three. 
      * */
    // copy constructor
    AcademicRecord(const AcademicRecord& src)
    {
      this->math = src.math;
      this->computers = src.computers;
      this->physics = src.physics;
    }
    // assignment operator
    AcademicRecord& operator=(const AcademicRecord& rhs)
    {
      this->math = rhs.math;
      this->computers = rhs.computers;
      this->physics = rhs.physics;
      return *this;
    }
    // destructor
    // ~AcademicRecord();
    
    // operators
    void check_bounds(); // prevent operators from going out of bounds
    AcademicRecord operator++()
    {
      this->math += 10;
      this->computers += 10;
      this->physics += 10;
      this->check_bounds();
      return *this;
    }  // prefix overload
    // AcademicRecord operator++(int); // postfix overload
    // AcademicRecord operator--(); // prefix overload
    // AcademicRecord operator--(int); // postfix overload
    // AcademicRecord operator+=(int i);
    // AcademicRecord operator-=(int i);
    bool operator==(const AcademicRecord& rhs);

    // print function
    std::string print() const;
};

#endif