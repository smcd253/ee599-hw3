#include <iostream>
#include <fstream>
#include <stdio.h>

#include "src/lib/solution.h"

int main()
{
    int usr_in = 0;
    std::vector<int> input = {1, 4, 5, 23, 100, 12, 18, 175};
    vector_interact vi(input);

    FILE* f = fopen("/media/shmcdono/Storage/USC/ee599/ee599-hw3/q6-vect_reader/output.txt","w");

    while(usr_in != 5)
    { 
        vi.print_menu(f);
        while((usr_in = (int)fgetc(stdin) - 48) < 0){}
        fputc((char)usr_in, f);
        vi.print_result(f, usr_in);  
    }

    fclose(f);

    return EXIT_SUCCESS;
}