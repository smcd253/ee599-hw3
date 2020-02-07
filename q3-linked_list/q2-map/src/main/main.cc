#include <iostream>
#include "src/lib/solution.h"

int main()
{
    Solution solution ;
    std::vector<int> input = {3, 7, 11, 15};
    int sum = 10;
    std::vector<int> output = solution.fit_sum(input, sum);
    if(output.size() == 2)
    {
        
        printf("output = {%d, %d}\n", output[0], output[1]);
    }
    else if (output.size() == 0)
    {
        printf("output = {}\n");
    }
    else
    {
        for (auto n : output)
        {
            printf("%d", n);
        }
        printf("\n");
    }
     
    return EXIT_SUCCESS;
}