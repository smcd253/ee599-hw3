#include "solution.h"


 
std::string menu =
"*********************************************************************\n" 
"*\n" 
"Please choose any of the following options:\n" 
"\t1. What is the first element?\n" 
"\t2. What is the last element?\n" 
"\t3. What is the current element?\n" 
"\t4. What is the ith element from the current location?\n" 
"\t5. Exit.\n" 
"*********************************************************************\n";

void vector_interact::print_menu(FILE* f)
{
  // print vector and menu
  fprintf(f, "*********************************************************************\n*\n");
  printf("*********************************************************************\n*\n");
  fprintf(f, "Vector: ");
  printf("Vector: ");
  for (int i = 0; i < (int)this->my_vector.size(); i++)
  {
    if (i < (int)this->my_vector.size() - 1)
    {
      fprintf(f, "%d,", my_vector[i]);
      printf("%d,", my_vector[i]);
    }
    else
    {
      fprintf(f, "%d\n", my_vector[i]);
      printf("%d\n", my_vector[i]);
    }
  }
  fprintf(f, "%s", menu.data());
  printf("%s", menu.data());
}

void vector_interact::print_result(FILE* f, int usr_in)
{
  int i = 0;
  if(usr_in == 4)
  {
      fprintf(f, "Enter the value of i::\n");
      printf("Enter the value of i::\n");
      std::cin >> i;
      if (i <= -1)
      {
        fprintf(f, "Output: i cannot be negative.\n");
        printf("Output: i cannot be negative.\n");
        return;
      }
      i += this->current_location;
      this->current_location = i;
  }
  else if (usr_in == 2)
  {
      i = (int)this->my_vector.size() - 1;
  }
  else if (usr_in == 5)
  {
    return;
  }
  if(i >= (int)this->my_vector.size())
  {
    printf("Output: Sorry! You cannot traverse %d elements from your current location.\n", i);
    return;
  }
  else
  {
    printf("%d\n",this->my_vector[i]);
  }
}