#include <iostream>
#include "src/lib/solution.h"

using std::cout;
using std::endl;

int main()
{
    AcademicRecord obj1;
    obj1.math = 5;
    obj1.computers = 10;
    obj1.physics = 95;
    cout<< "Value before incrementation ::\n" << obj1.print() << endl;
    obj1++;
    cout<< "Value after incrementation ::\n"<< obj1.print() << endl;
    obj1--;
    cout<< "Value after decrementation ::\n"<< obj1.print() << endl;
    AcademicRecord obj2=obj1;
    cout<< "Value of Object 2::\n" << obj2.print() << endl;
    obj2+=50;
    cout<< "Value of Object 2 after increasing marks by 50 for each subject::\n" << obj2.print() << endl;
    obj2-=30;
    cout<< "Value of Object 2 after decreasing marks by 30 for each subject::\n" << obj2.print() << endl;
    
    return EXIT_SUCCESS;
}