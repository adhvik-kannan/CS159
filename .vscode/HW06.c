#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 15 // SIZE OF THE ARRAY
#define LOWVAL 1 // LOWEST RANGE OF NUMBERS
#define HIGHVAL 1000000 // HIGHEST RANGE OF NUMBERS

// FUNCTION DELCARATIONS
int askInformation();
int findMaxSquare(int);
int checkPerfectSquare(int);
void printResults(int, int, int);
void noMaxSquares();
int setCount();
int mappingToRange(int);

int main()
{
  // LOCAL DECLARATIONS
  int seed; // USER-ENTERED POSITIVE SEED VALUE
  int numbers[SIZE]; // ARRAY OF SIZE 15 THAT HOLDS ALL THE RANDOMLY GENERATED NUMBERS
  int i; // ITERATING INDEX
  int maxSquare; // CALCULATED LARGEST SQUARE DIVISOR
  int count; // COUNTING VARIABLE THAT KEEPS TRACK OF HOW MANY TIMES THE printResults() FUNCTION IS CALLED

  // EXECUTABLE STATEMENTS
  seed = askInformation();
  srand(seed);
  count = setCount();
  
  for(i = 0; i < SIZE; i++)
  {
    numbers[i] = rand();
    numbers[i] = mappingToRange(numbers[i]);
  }
  for(i = SIZE - 1; i >= 0; i--)
  {
    maxSquare = findMaxSquare(numbers[i]);
    if(maxSquare > 1)
    {
      printResults(i, maxSquare, numbers[i]);
      count++;
    }
  }

  if(count == 0)
  {
    noMaxSquares();
  }

  return 0;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: mappingToRange
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int num - Randomly generated number from the array in main that needs to be mapped to between 1 and 1,000,000.
*
*  Function Description: This function takes a randomly generated number and maps it to be between 1 and 1,000,000.
*
***************************************************************************/

int mappingToRange(int num)
{
  // EXECUTABLE STATEMENTS
  num = num % (HIGHVAL - LOWVAL + 1) + LOWVAL;
  return num;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: setCount
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line): None
*
*  Function Description: This function sets the count variable to be 0.
*
***************************************************************************/

int setCount()
{
  // EXECUTABLE STATEMENTS
  return 0;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: noMaxSquares
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line): None
*
*  Function Description: This function is called when count equals 0, and prints that the 15 numbers in the data set do not have a max square divisor greater than one.
*
***************************************************************************/

void noMaxSquares()
{
  // EXECUTABLE STATEMENTS
  printf("Note: Data set contains no values with a max square divisor greater than one.\n");
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: printResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int index - The current index that the array is on
*    2. int maxSquare - The calculated maxSquare of the corresponding number.
*    3. int value - The randomly generated number that was mapped to between 1 and 1,000,000 and is at the index being passed.
*
*  Function Description: This function prints the results of the program.
*
***************************************************************************/

void printResults(int index, int maxSquare, int value)
{
  printf("Index: %d Value - %d Max Square - %d\n", index, value, maxSquare);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: askInformation()
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line): None
*
*  Function Description: This function asks the user to enter a seed value. It also uses input validation to ensure that a positive non-zero integer is entered.
*
***************************************************************************/

int askInformation()
{
  // LOCAL DECLARATIONS
  int seed; // USER-ENTERED SEED VALUE

  // EXECUTABLE STATEMENTS
  do
  {
    printf("Enter seed value -> ");
    scanf("%d", &seed);
    printf("\n");
    if(seed <= 0)
    {
      printf("Error! Seed must be a positive integer value!!\n\n");
    }
  }  while(seed <= 0);
  return seed;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: findMaxSquare
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int num - Number that is randomly generated and at a certain index in the array
*
*  Function Description: This function iterates through all values below the number and checks to see if any of them are divisors. If they are, the function checks to see if the number is a perfect square, and if it is, it checks to see if the number equals the index. If they are equal, then it doesn't change the max square value, but if they aren't, then it changes the max square value to its new value of i. However, if the divisor isn't a perfect square, it doesn't change the max value. 
*
***************************************************************************/

int findMaxSquare(int num)
{
  // LOCAL DECLARATIONS
  int i; // ITERATING INDEX AND VALUE OF THE NUMBERS BEING DIVIDED BY num TO CHECK IF THEY ARE DIVISORS
  int max; // THE MAX SQUARE DIVISOR VALUE
  // EXECUTABLE STATEMENTS
  for(i = 1; i <= num; i++)
  {
    if(num % i == 0)
    {
      if(checkPerfectSquare(i))
      {
        if(num == i)
        {
          max = max;
        }
        else
        {
          max = i;
        }
      }
      else
      {
        max = max;
      }
    }
  }
  return max;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: checkPerfectSquare
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int num - Number that was found to be a divisor
*
*  Function Description: This function checks to see if the divisor found in findMaxSquare is a perfect square or not. It does this by comparing num to the square root of num times the square root of num. The roots are casted to be integers as the sqrt() function returns a double. 
*
***************************************************************************/

int checkPerfectSquare(int num)
{
  // EXECUTABLE STATEMENTS
  return (num == (int) sqrt(num) * (int) sqrt(num));
}