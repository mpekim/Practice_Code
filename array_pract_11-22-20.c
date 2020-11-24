#include <stdio.h>
#include <cstdlib.h>

/********************************
Author: Mike Morley
Date: November 22nd, 2020

Time Spent: About 1 hour.

Credited Sources of Help:
- Computing I (Class at Umass Lowell)

Program Purpose:
- Basic array training, getting used
to coding on GitHub, without the aid
of typo-correction and other factors
of IDEs.
*********************************/

int* create_int_arr_default(int size);
int** create_2d_int_arr_default(int rows, int columns);
void destroy_int_array(int** phList);

// Function Declarations.
//-------------------------------------------------------------------

int main(int argc, char* argv[])
{
  return 0;
}

//-------------------------------------------------------------------
// Function Implementations.

// Pre-Condition: This function accepts an int value, for the size of the array.
// Post-Condition: A dynamically allocated int array will be made of the desired size.
// Since this is a "default" array, all values will be set to zero.
int* create_int_arr_default(void)
{
  int* list = (int*)malloc(sizeof(int) * size);
  // Allocate the memory for the function, and check to see if it was a success.
  
  if (list == NULL)
  {
  printf("Error: Unable to allocate memory for the default int array. Ending program.\n");
  exit(1);
    // If the memory was NOT allocated, then end the program.
  }
  
  // If the memory has been successfully allocated, then set the values.
  // Since this is a default array, all of the values will be set to zero.
  for (int i = 0; i < size; i++)
  {
    list[i] = 0;
  }
  
  return list;
}

// Pre-Condition: This function accepts two int arguments, for the rows and columns
// of the "table" (2d array).
// Post-Condition: A 2D array will be created. Since this is a default array, all
// of the values will be set to zero.
int** create_2d_int_arr_default(int rows, int columns)
{
  int** new_table;
  
  // Allocate the memory for the number of rows.
  new_table = (int**)malloc(sizeof(int*) * rows);
  
  // Check to see that the memory has been allocated. If not, end the program.
  if (new_table == NULL)
  {
      printf("Error: unable to allocate memory for the 2D Array. Ending program.\n");
    exit(1);
  }
  
  // If the memory has been allocated, then call the 1D Array function for the columns.
  for (int i = 0; i < rows; i++)
  {
    new_table[i] = create_int_arr_default();
  }
  
  // Return the pointer to the table.
  return new_table;
}

// Pre-Condition: This function accepts a pointer to handle to int
// (In essence, it is a double int pointer).
// Post-Condition: The array of ints will be destroyed, and the memory
// will be freed.
void destroy_int_array(int** phList)
{
  // Check to see if there is memory to be destroyed. If not, end the program.

  if (*phList == NULL)
  {
    printf("Error: Unable to find memory to delete. Ending program.\n");
    exit(1);
  }
  
    // If there is memory, then delete it and set the pointer to NULL.
    free(*phList);
    *phList = NULL;
    
  return;
}
