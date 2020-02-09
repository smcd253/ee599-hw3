#include <iostream>
#include <stdio.h>
#include "src/lib/solution.h"

int main()
{
    int usr_in = 0;
    std::vector<int> input = {1, 4, 5, 23, 100, 12, 18, 175};
    vector_interact vi(input);
    FILE* f = fopen("q6_output.txt","w");
    while(usr_in != 5)
    { 
        vi.print_menu(f);
        std::cin >> usr_in;
        vi.print_result(f, usr_in);  
    }
    fclose(f);
    
    return EXIT_SUCCESS;
}