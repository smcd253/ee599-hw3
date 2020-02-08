#include "solution.h"

/****** Other Functions ******/
// Runtime = 6 --> O(1)
void AcademicRecord::check_bounds()
{
    // check upper bounds
    if(this->math > 100)
    {
        this->math = 100;
    }
    // check lower bounds
    else if(this->math < 0)
    {
        this->math = 0;
    }

    // check upper bounds
    if(this->computers > 100)
    {
        this->computers = 100;
    }
    // check lower bounds
    else if(this->computers < 0)
    {
        this->computers = 0;
    }

    // check upper bounds
    if(this->physics > 100)
    {
        this->physics = 100;
    }
    // check lower bounds
    else if(this->physics < 0)
    {
        this->physics = 0;
    }
}

// Runtime = 4 + 36 + 2 --> O(1)
std::string AcademicRecord::print() const
{
    std::string format = "Math::%d\nComputers::%d\nPhysics::%d\n";
    std::string result;
    result.reserve(format.size() + 6); // reserve enough space to hold 3 100s
    char buffer[format.size() + 6];

    sprintf(buffer, format.data(), 
            this->math, this->computers, this->physics);
    result = buffer;
    return result;
}