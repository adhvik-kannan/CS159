#include<stdio.h>
#include<stdlib.h>

// FUNCTION DECLARATIONS

int askInformation(int, int); //Asks the user for input information
int checkPrime(int); //Checks whether a number is prime and returns a 1 or 0
int calculation(int,int,int, int, int); //Calculates our random #s, checks if they're prime and counts them
void printResults(int, int, int, int); //Prints results to console

int main()
{
  // local declarations
  int seed; //Seed for srand
  int dataSize; //Number of #s to be calculated as input by user
  int lowVal; //Low range constraint value
  int highVal; //High range constraint value
  int result1; //Results for line 1
  int result2; //Reults for line 2

  // executable statements
  seed = askInformation(1, 0);
  dataSize = askInformation(2, 0);
  lowVal = askInformation(3, 0);
  highVal = askInformation(4, lowVal);

  srand(seed);
  result1 = calculation(dataSize, lowVal, highVal, lowVal, lowVal + (highVal - lowVal) / 2);
  srand(seed);
  result2 = calculation(dataSize, lowVal, highVal, lowVal + (highVal - lowVal) / 2 + 1 , highVal);
  printResults(lowVal,highVal,result1, result2);

  return 0;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:askInformation
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.option - int - input of 1 2 or 3 to determine message printed
*    2.lowVal previously acquired by this function for user in print output
*
*  Function Description: One of several optional messages is displayed and user input is taken
*
***************************************************************************/

int askInformation(int option, int lowVal)
{
  // LOCAL DECLARATIONS
  int info; //Value to be returned
  // EXECUTABLE STATEMENT
  if(option == 1)
  {
    printf("Enter seed value -> ");
    scanf("%d", &info);
    if(info <= 0)
    {
      do
      {
        printf("\nError! Seed must be a positive integer value!!\n");
        printf("\nEnter seed value -> ");
        scanf("%d", &info);
      } while(info <= 0);
    }
  }
  if(option == 2)
  {
    printf("Enter quantity of data to generate -> ");
    scanf("%d", &info);
    if(info <= 0)
    {
      do
      {
        printf("\nError! Data set size must be a positive integer value!!\n");
        printf("\nEnter quantity of data to generate -> ");
        scanf("%d", &info);
      } while(info <= 0);
    }
  }

  if(option == 3)
  {
    printf("Enter smallest value to generate -> ");
    scanf("%d", &info);
    if(info < 0)
    {
      do
      {
        printf("\nError! Smallest value for range is zero!!\n");
        printf("\nEnter smallest value to generate -> ");
        scanf("%d", &info);
      } while(info < 0);
    }
  }
  
  if(option == 4)
  {
    printf("Enter largest value to generate -> ");
    scanf("%d", &info);
    if(info == lowVal)
    {
      info = lowVal;
    }
    else if(info < 10)
    {
      do
      {
        printf("\nError! Largest value must be >= 10\n");
        printf("\nEnter largest value to generate -> ");
        scanf("%d", &info);
      } while(info < 10);
    }
  }

  return info;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:checkPrime
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.num - int - number to be checked for prime status
*
*  Function Description:Checks if a number is prime and returns 1 or 0 depending on the result
*
***************************************************************************/

int checkPrime(int num)
{
  int i; //loop control variable
  int flag; //status to be returned
  flag = 1;

  //Executables
  for (i = 2; i <= num / 2; i++)
  {
    if (num % i == 0)
    {
      flag = 0;
    }
  }

  return flag;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:calculation
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1. dataSize - int - number of #s to be generated
*    2. lowVal - int - low constraint of range
*    3. highVal - int - high constraint of range
*    4. botrange - int bottom range constraint
*    5. topRange - int - top range constraint
*
*  Function Description:generates random numbers and check to see if they're prime
*
***************************************************************************/
int calculation(int dataSize,int lowVal,int highVal, int botRange, int topRange)
{
  //Local Variable Declarations
  int counter; //counter variable
  int i; //loop control variable
  int ranNum; //random number to be generated

  //Executable Statements
  counter = 0;
  for(i = 0; i < dataSize; i++)
  {
    ranNum = rand();
    ranNum = ranNum % (highVal - lowVal + 1) + lowVal;

    if(ranNum == 1 || ranNum == 0)
    {
      counter += 0;
    }
    else if(ranNum <= topRange && ranNum >= botRange)
    {
      counter += checkPrime(ranNum);
    }
    else
    {
      counter += 0;
    }
  }

  return(counter);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:printResults
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.lowVal - int - low constraint of range
*    2.highVal - int - high constraint of range
*    3. result1 - int - result 1
*    4. result2 - int - result 2
*
*  Function Description:Prints final calculated values to screen
*
***************************************************************************/
void printResults(int lowVal, int highVal, int result1, int result2)
{
  if(lowVal == highVal)
  {
    printf("\nPrime numbers identified in range [%d, %d]: None", lowVal, highVal);
  }
  else if (result1 == 0)
  {
    printf("\nPrime numbers identified in range [%d, %d]: None", lowVal, lowVal + (highVal - lowVal) / 2 );
    printf("\nPrime numbers identified in range [%d, %d]: %d\n", lowVal + (highVal - lowVal) / 2 + 1 , highVal , result2);
  }
  else if (result2 == 0)
  {
    printf("\nPrime numbers identified in range [%d, %d]: %d", lowVal, lowVal + (highVal - lowVal) / 2,  result1);
    printf("\nPrime numbers identified in range [%d, %d]: None\n",lowVal + (highVal - lowVal) / 2 + 1 , highVal );
  }
  else
  {
    printf("\nPrime numbers identified in range [%d, %d]: %d", lowVal,  lowVal + (highVal - lowVal) / 2 , result1);
    printf("\nPrime numbers identified in range [%d, %d]: %d\n", lowVal + (highVal - lowVal) / 2 + 1 , highVal , result2);
  }
}