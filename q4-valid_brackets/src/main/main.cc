#include <iostream>
#include "src/lib/solution.h"

int main()
{
    Solution solution;
    std::string input = "(a+b)";
    bool actual = solution.valid_brackets(input);
    printf("Q: Does %s have valid brackets?\nA: %s\n", input.data(), actual ? "Yes" : "No");
    
    input = "(a+b)[c*d]{5g+h}";
    actual = solution.valid_brackets(input);
    printf("Q: Does %s have valid brackets?\nA: %s\n", input.data(), actual ? "Yes" : "No");

    input = "(a+b]";
    actual = solution.valid_brackets(input);
    printf("Q: Does %s have valid brackets?\nA: %s\n", input.data(), actual ? "Yes" : "No");

    input = "(7h+[5c)+7]";
    actual = solution.valid_brackets(input);
    printf("Q: Does %s have valid brackets?\nA: %s\n", input.data(), actual ? "Yes" : "No");

    input = "{2k+[5j]}";
    actual = solution.valid_brackets(input);
    printf("Q: Does %s have valid brackets?\nA: %s\n", input.data(), actual ? "Yes" : "No");

    input = "{2k++[5--*j]}";
    actual = solution.valid_brackets(input);
    printf("Q: Does %s have valid brackets?\nA: %s\n", input.data(), actual ? "Yes" : "No");

    return EXIT_SUCCESS;
}