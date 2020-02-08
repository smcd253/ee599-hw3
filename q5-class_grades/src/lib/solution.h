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
    // Runtime = 5 --> O(1)
    AcademicRecord() : max_grade(100), min_grade(0), math(0), computers(0), physics(0) {}
    // parametrized
    // Runtime = 5 --> O(1)
    AcademicRecord(int x, int y, int z) : max_grade(100), min_grade(0), math(x), computers(y), physics(z) {}
    /** Rule of Three
      * If a class requires a user-defined destructor, 
      * a user-defined copy constructor, or a user-defined copy assignment operator, 
      * it almost certainly requires all three. 
      * */
    // copy constructor
    // Runtime = 6 --> O(1)
    AcademicRecord(const AcademicRecord& src)
    {
      this->max_grade = 100;
      this->min_grade = 0;
      this->math = src.math;
      this->computers = src.computers;
      this->physics = src.physics;
    }
    // assignment operator
    // Runtime = 6 --> O(1)
    AcademicRecord& operator=(const AcademicRecord& rhs)
    {
      this->max_grade = 100;
      this->min_grade = 0;
      this->math = rhs.math;
      this->computers = rhs.computers;
      this->physics = rhs.physics;
      return *this;
    }
    // destructor
    // ~AcademicRecord();
    
    // operators
    void check_bounds(); // helper fn to prevent operators from going out of bounds
    // Runtime =  3 + 6 + 1 --> O(1)
    AcademicRecord operator++() // prefix overload
    {
      this->math += 10;
      this->computers += 10;
      this->physics += 10;
      this->check_bounds();
      return *this;
    }  
    AcademicRecord operator++(int) // postfix overload
    {
        this->math += 10;
        this->computers += 10;
        this->physics += 10;
        this->check_bounds();
        return *this;
    }
    AcademicRecord operator--()
    {
        this->math -= 20;
        this->computers -= 20;
        this->physics -= 20;
        this->check_bounds();
        return *this;
    }
    AcademicRecord operator--(int)
    {
        this->math -= 20;
        this->computers -= 20;
        this->physics -= 20;
        this->check_bounds();
        return *this;
    }
    AcademicRecord operator+=(int i)
    {
        this->math += i;
        this->computers += i;
        this->physics += i;
        this->check_bounds();
        return *this;
    }
    AcademicRecord operator-=(int i)
    {
        this->math -= i;
        this->computers -= i;
        this->physics -= i;
        this->check_bounds();
        return *this;
    }

    // comparison operator
    // Runtime = 11 --> O(1)
    bool operator==(const AcademicRecord& rhs)
    {
        bool result = true;
        if(this->math != rhs.math)
        {
            result = false;
        }
        if(this->computers != rhs.computers)
        {
            result = false;
        }
        if(this->physics != rhs.physics)
        {
            result = false;
        }

        return (this->math == rhs.math) && 
                (this->computers == rhs.computers) && 
                (this->physics == rhs.physics);
    }

    // print function
    std::string print() const;
};

#endif