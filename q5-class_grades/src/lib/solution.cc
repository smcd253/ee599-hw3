#include "solution.h"


/****** Constructors ******/
// copy constructor
// inline AcademicRecord::AcademicRecord(const AcademicRecord& src)
// {
//     this->math = src.math;
//     this->computers = src.computers;
//     this->physics = src.physics;
// }

// assignment operator
// AcademicRecord& AcademicRecord::operator=(const AcademicRecord& rhs)
// {
//     this->math = rhs.math;
//     this->computers = rhs.computers;
//     this->physics = rhs.physics;
// }

/****** Destructors ******/
// AcademicRecord::~AcademicRecord()
// {
//     delete this;
// }

/****** Other Operators ******/
// AcademicRecord AcademicRecord::operator++()
// {
//     this->math += 10;
//     this->computers += 10;
//     this->physics += 10;
//     this->check_bounds();
// }

// AcademicRecord AcademicRecord::operator++(int)
// {
//     this->math += 10;
//     this->computers += 10;
//     this->physics += 10;
//     this->check_bounds();
// }

// AcademicRecord AcademicRecord::operator--()
// {
//     this->math -= 20;
//     this->computers -= 20;
//     this->physics -= 20;
//     this->check_bounds();
// }

// AcademicRecord AcademicRecord::operator--(int)
// {
//     this->math -= 20;
//     this->computers -= 20;
//     this->physics -= 20;
//     this->check_bounds();
// }

// AcademicRecord AcademicRecord::operator+=(int i)
// {
//     this->math += i;
//     this->computers += i;
//     this->physics += i;
//     this->check_bounds();
// }

// AcademicRecord AcademicRecord::operator-=(int i)
// {
//     this->math -= i;
//     this->computers -= i;
//     this->physics -= i;
//     this->check_bounds();
// }

// bool AcademicRecord::operator==(const AcademicRecord& rhs)
// {
//     // bool result = true;
//     // if(this->math != rhs.math)
//     // {
//     //     result = false;
//     // }
//     // if(this->computers != rhs.computers)
//     // {
//     //     result = false;
//     // }
//     // if(this->physics != rhs.physics)
//     // {
//     //     result = false;
//     // }

//     return (this->math == rhs.math) && 
//             (this->computers == rhs.computers) && 
//             (this->physics == rhs.physics);
// }

/****** Other Functions ******/
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

std::string AcademicRecord::print() const
{
    std::string format = "Math::%d\nComputers::%d\nPhysics::%d\n";
    std::string result;
    result.reserve(format.size() + 6); // reserve enough space to hold 3 100s
    // char buffer[format.size() + 6];

    sprintf((char*)result.data(), format.data(), 
            this->computers, this->computers, this->physics);
    return result;
}