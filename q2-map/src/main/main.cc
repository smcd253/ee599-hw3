#include <iostream>
#include "src/lib/solution.h"

int main()
{
    Solution solution ;
    int a = 1;
    int b = 2;
    std::string str1 = "ba";
    std::string str2 = "rump";

    std::cout << solution.add(a, b) << std::endl;
    std::cout << solution.add(str1, str2) << std::endl;
    std::cout << solution.add(a, str2) << std::endl;
    std::cout << solution.add(str1, b) << std::endl;

    return EXIT_SUCCESS;
}