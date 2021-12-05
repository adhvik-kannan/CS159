#include<stdio.h>
#include<stdlib.h>

#define ARRSIZE 20 // Array Size

// Function Declarations
void generateValues(int*, int);
int askSeed();
void separate(int*);
void bubbleSort(int*, int, int);
int findLastIndex(int*);
int findGCD(int, int);
void printResults(int*, int*);

int main()
{
  // Local Declarations
  int nums[ARRSIZE]; // Array of randomly generated values
  int seed; // Value of the user-inputted seed
  int index; // The index of the last odd number
  int gcds[ARRSIZE - 1]; // Array of the greatest common divisors
  int i; // Iterating index

  // Executable Statements
  seed = askSeed();
  srand(seed);
  generateValues(nums, seed);

  separate(nums);
  index = findLastIndex(nums);
  bubbleSort(nums, index, 0);
  bubbleSort(nums, ARRSIZE, index);

  for(i = 0; i < ARRSIZE - 1; i++)
  {
    gcds[i] = findGCD(nums[i], nums[i + 1]);
  }
  printResults(nums, gcds);

  return 0;
}
/*****+-----**--**--****-*-*-----*--***-**--********************************
*
*  Function Information
*
*  Name of Function: printResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int nums[] - Array of randomly generated values
*    2. int gcds[] - Array of GCDs 
*
*  Function Description: This function prints the results of the sorting and the calculated GCDs in 2 different rows.
*
******+-----**--**--****-*-*-----*--***-**--*******************************/
void printResults(int nums[], int gcds[])
{
  // Local Declarations
  int i; // Iterating Index

  // Executable Statements
  printf("\nSorted Array:");
  for(i = 0; i < ARRSIZE; i++)
  {
    printf(" %d", nums[i]);
  }

  printf("\nGreatest Divisors:");
  for(i = 0; i < ARRSIZE - 1; i++)
  {
    printf(" %d", gcds[i]);
  }
  printf("\n");
}
/*****+---*--*--**--****-*-*-----*--***-**--********************************
*
*  Function Information
*
*  Name of Function: askSeed
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line): None
*
*  Function Description: This fuction asks the user to enter a seed value and validates that it is greater than 0. 
*
******+---*--*--**--****-*-*-----*--***-**--*******************************/
int askSeed()
{
  // Local Declarations
  int seed; // Value of user-inputted seed

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
/*****+---*--*--**--****-*-*-----*--***-**--********************************
*
*  Function Information
*
*  Name of Function: generateValues
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int nums[] - Array that has values generated into it
*    2. int seed - The seed that is passed so the rand() function can be mapped to the specific range.
*
*  Function Description: This function generates values between 1 and the seed value and stores them in the nums array.
*
******+---*--*--**--****-*-*-----*--***-**--*******************************/
void generateValues(int nums[], int seed)
{
  // Local Declarations
  int i; // Iterating index

  // Executable Statements
  for(i = 0; i < ARRSIZE; i++)
  {
    nums[i] = rand() % seed + 1;
  }
}
/*****+-*-*-***--*--****-*-*-----*--***-**--********************************
*
*  Function Information
*
*  Name of Function: findLastIndex
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int nums[] - Array of randomly generated numbers
*
*  Function Description: This function counts how many odd numbers there are and keeps track of where it should end in the sorted array.
*
******+-*-*-***--*--****-*-*-----*--***-**--*******************************/
int findLastIndex(int nums[])
{
  // Local Declarations
  int i; // Iterating index
  int count; // Count of how many odds

  // Executable Statements
  count = 0;
  for(i = 0; i < ARRSIZE; i++)
  {
    if(nums[i] % 2)
    {
      count++;
    }
  }
  return count;
}
/*****+---*-***--*--****-*-*-----*--***-**--********************************
*
*  Function Information
*
*  Name of Function: separate
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int nums[] - Array of randomly generated numbers
*
*  Function Description: This function separates the evens and the odds. It moves the odds to the left side and the evens to the right.
*
******+---*-***--*--****-*-*-----*--***-**--*******************************/
void separate(int nums[])
{
  // Local Declarations;
  int i; // Outer loop iterating index (how many times the "sort" is done.
  int j; // Inner loop iterating index
  int temp; // Variable used to swap data between two different array indexes.

  // Executable Statements
  for(i = 1; i < ARRSIZE; i++)
  {
    for(j = 0; j < ARRSIZE - i; j++)
    {
      if(nums[j] % 2 == 0)
      {
        temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
      }
    }
  }
}
/*****+-----***--*--****-*-*-----*--***-**--********************************
*
*  Function Information
*
*  Name of Function: bubbleSort
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int nums[] - Array of randomly generated values that is separated by odd and evens
*    2. int end - The last index of the sorting range
*    3. int start - The start of the sorting range
*
*  Function Description: This function is the bubble sort from the notes packet and sorts arrays from least to greatest
*
******+-----***--*--****-*-*-----*--***-**--*******************************/
void bubbleSort(int nums[], int end, int start)
{
  // Local Declarations
  int i; // Outer loop iterating index
  int j; // Inner loop iterating index and sorting function
  int temp; // Variable used to swap data between two indexes

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
/*****+---*--**--*--****-*-*-----*--***-**--********************************
*
*  Function Information
*
*  Name of Function: findGCD
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int num1 - First number to be compared
*    2. int num2 - Second number to be compared
*
*  Function Description: This function finds the greatest common divisor for 2 numbers
*
******+---*--**--*--****-*-*-----*--***-**--*******************************/
int findGCD(int num1, int num2)
{
  // Local Declarations
  int i; // Iterating Index
  int gcd; // Greatest Common Divisor

  // Executable Statements
  gcd = 0;
  for(i = 1; i <= num1 && i <= num2; i++)
  {
    if(num1 % i == 0 && num2 % i == 0)
    {
      gcd = i;
    }
  }
  return gcd;
}