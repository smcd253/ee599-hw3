#include "solution.h"


/****** Constructors ******/
// copy constructor
Grades::Grades(const Grades& src)
{
    this->math = src.math;
    this->computers = src.computers;
    this->physics = src.physics;
}

// assignment operator
Grades& Grades::operator=(const Grades& rhs)
{
    this->math = rhs.math;
    this->computers = rhs.computers;
    this->physics = rhs.physics;
}

/****** Destructors ******/
// Grades::~Grades()
// {
//     delete this;
// }

/****** Other Operators ******/
Grades Grades::operator++()
{
    this->math += 10;
    this->computers += 10;
    this->physics += 10;
    this->check_bounds();
}

Grades Grades::operator++(int)
{
    this->math += 10;
    this->computers += 10;
    this->physics += 10;
    this->check_bounds();
}

Grades Grades::operator--()
{
    this->math -= 20;
    this->computers -= 20;
    this->physics -= 20;
    this->check_bounds();
}

Grades Grades::operator--(int)
{
    this->math -= 20;
    this->computers -= 20;
    this->physics -= 20;
    this->check_bounds();
}

Grades Grades::operator+=(int i)
{
    this->math += i;
    this->computers += i;
    this->physics += i;
    this->check_bounds();
}

Grades Grades::operator-=(int i)
{
    this->math -= i;
    this->computers -= i;
    this->physics -= i;
    this->check_bounds();
}

bool Grades::operator==(const Grades& rhs)
{
    // bool result = true;
    // if(this->math != rhs.math)
    // {
    //     result = false;
    // }
    // if(this->computers != rhs.computers)
    // {
    //     result = false;
    // }
    // if(this->physics != rhs.physics)
    // {
    //     result = false;
    // }

    return (this->math == rhs.math) && 
            (this->computers == rhs.computers) && 
            (this->physics == rhs.physics);
}

/****** Get Functions ******/
int Grades::get_math()
{
    return this->math;
}

int Grades::get_computers()
{
    return this->computers;
}

int Grades::get_physics()
{
    return this->physics;
}

/****** Other Functions ******/
void Grades::check_bounds()
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

// print helper function
std::string string_format(const std::string fmt_str, ...) {
    int final_n, n = ((int)fmt_str.size()) * 2; /* Reserve two times as much as the length of the fmt_str */
    std::unique_ptr<char[]> formatted;
    va_list ap;
    while(1) {
        formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
        strcpy(&formatted[0], fmt_str.c_str());
        va_start(ap, fmt_str);
        final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
        va_end(ap);
        if (final_n < 0 || final_n >= n)
            n += abs(final_n - n + 1);
        else
            break;
    }
    return std::string(formatted.get());
}

std::string Grades::print() const
{
    std::string format = "Math::%d\nComputers::%d\nPhysics::%d\n";
    std::string result;
    result.reserve(format.size() + 6); // reserve enough space to hold 3 100s
    // char buffer[format.size() + 6];

    sprintf(result.data(), format.data(), 
            this->computers, this->computers, this->physics);
    return result;
}