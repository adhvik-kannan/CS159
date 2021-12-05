#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 25 // Array Size

// Function Declarations
int askSeed();
void generateValues(int*);
void findLargestValue(int*);
void bubbleSort(int*, int, int);
void printResults(int*);

int main()
{
  // Local Declarations
  int nums[SIZE]; // Array of randomly generated numbers
  int seed; // Positive integer for seed value

  // Executable Statements
  seed = askSeed();
  srand(seed);

  generateValues(nums);
  findLargestValue(nums);
  bubbleSort(nums, SIZE, 0);

  printResults(nums);
  return 0;
}

/*****+-*----**--*--**-***-**----*--***-**--********************************
*
*  Function Information
*
*  Name of Function: printResults 
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int nums[] - Array holding the randomly generated numbers
*
*  Function Description: This function iterates through the array and prints out the rows and 5 numbers per row in a sorted order. It uses a count variable to move to the next line.
*
******+-*----**--*--**-***-**----*--***-**--*******************************/
void printResults(int nums[])
{
  // Local Declarations
  int i; // Iterating index
  int count; // Counts how many numbers have been printed in each row and at 5, starts printing the next row. 
  int row; // The current row

  // Executable Statements
  count = 1;
  row = 1;
  printf("\n");
  for(i = 0; i < SIZE; i++)
  {
    if(count == 1)
    {
      printf("Row %d:", row);
    }
    if(count == 5)
    {
      printf(" %d", nums[i]);
      row++;
      count = 1;
      printf("\n");
    }
    else
    {
      printf(" %d", nums[i]);
      count++;
    }
  }
}
/*****+-----**---*--**-***-**----*--***-**--********************************
*
*  Function Information
*
*  Name of Function: findLargestValue
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int nums[] - Array of randomly generated numbers
*    
*  Function Description: This function iterates through each value of the array and applies the formulas given until it reaches 1. While doing this, it keeps track of the highest number that isn't a power of two.
*
******+-----**---*--**-***-**----*--***-**--*******************************/
void findLargestValue(int nums[])
{
  // Local Declarations
  int i; // Iterating index 
  int max; // Holds the maximum number that isn't a power of 2.

  // Executable Statements
  max = 0;
  for(i = 0; i < SIZE; i++)
  {
    max = nums[i];
    if(ceil(log2(nums[i])) == floor(log2(nums[i])))
    {
      nums[i] = 0;
    }
    else
    {
      while(nums[i] > 1)
      {
        if(nums[i] % 2)
        {
          nums[i] = nums[i] * 3 + 1;
        }
        else
        {
          nums[i] /= 2;
        }
        if(nums[i] > max && (ceil(log2(nums[i])) == floor(log2(nums[i]))) == 0 )
        {
          max = nums[i];
        }
      }
      nums[i] = max;
    }
  }
}
/*****+-*-*--**-***--*-***-**----*--***-**--********************************
*
*  Function Information
*
*  Name of Function: bubbleSort
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int nums[] - Array of randomly generated numbers
*    2. int end - Ending of the search area
*    3. int start - Starting of the search area
*
*  Function Description: This function is a bubble sort from the notes packet that sorts the array from least to greatest. The start and end parameters create the area for the sort to work in, which in this assignment, is the whole array.
*
******+-*-*--**-***--*-***-**----*--***-**--*******************************/
void bubbleSort(int nums[], int end, int start)
{
  // Local Declarations
  int i; // Iterating Index for outer loop and amount of times the sort should be executed
  int j; // Iterating index for inner loop and executes the sorting.
  int temp; // Temporary variable that holds the value of the current j-index to make swapping possible. 

  // Executable Statements
  for(i =  1; i < end; i++)
  {
    for(j = start; j < end - i; j++)
    {
      if(nums[j] > nums[j + 1])
      {
        temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
      }
    }
  }
}

/*****+-*-*-**--***--*-***-**----*--***-**--********************************
*
*  Function Information
*
*  Name of Function: generateValues
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int nums[]
*
*  Function Description: This function randomly generates 25 values and places them in the array. The seed is set in main.
*
******+-*-*-**--***--*-***-**----*--***-**--*******************************/
void generateValues(int nums[])
{
  // Local Declarations
  int i; // Iterating index 

  // Executable Statements
  for(i = 0; i < SIZE; i++)
  {
    nums[i] = rand() % 100 + 1;
  }
}

/*****+---*-**--***--*-***-**----*--***-**--********************************
*
*  Function Information
*
*  Name of Function: askSeed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line): None
*
*  Function Description: This function asks the user to enter a seed value and validates that their input is a positive integer. It then returns this entered value.
*
******+---*-**--***--*-***-**----*--***-**--*******************************/
int askSeed()
{
  // Local Declarations
  int seed; // Seed value that is validated and returned

  // Executable Statements
  do
  {
    printf("Enter seed value -> ");
    scanf("%d", &seed);
    if(seed <= 0)
    {
      printf("\nError! Seed must be a positive integer value!!\n\n");
    }
  } while(seed <= 0);

  return seed;
}