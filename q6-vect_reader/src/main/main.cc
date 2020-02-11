#include <iostream>
#include <fstream>
#include <stdio.h>

#include "src/lib/solution.h"

int main(int argc, char* argv[])
{
    int usr_in = 0;
    std::vector<int> input = {1, 4, 5, 23, 100, 12, 18, 175};
    vector_interact vi(input);
    std::vector<int> pre_def = {1, 2, 3, 1, 3, 4, 2, 5};
    int pd_ind = 0;

    int selection = 0;
    printf("Enter 1 for user input or 2 for pre-defined input: ");
    std::cin >> selection;

    printf("%s\n", argv[1]);
    FILE* f = fopen(argv[1],"w");

    while(usr_in != 5)
    { 
        vi.print_menu(f);
        switch (selection)
        {
            case (1):
                while((usr_in = (int)fgetc(stdin) - 48) < 0){}
                fputc((char)usr_in, f);
                vi.print_result(f, usr_in, -1);
            break;
                
            case (2):
                usr_in = pre_def[pd_ind];
                fprintf(f,"inserting input from main\n");
                fprintf(f, "%d\n", usr_in);
                if(pd_ind == (int)pre_def.size() - 3)
                {
                    pd_ind++;
                    vi.print_result(f, usr_in, pre_def[pd_ind]);
                }
                else
                {
                    vi.print_result(f, usr_in, -1);
                }
                pd_ind++;
            break;

            default:
                return EXIT_FAILURE;
            break;
        }
          
    }

    fclose(f);

    return EXIT_SUCCESS;
}