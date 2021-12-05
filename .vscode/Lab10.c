#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define ARRSIZE 10000
// FUNCTION DECLARATIONS
int askInformation(int, int);
void generateValues(int*);
void printResults(int, double, double, double, double);
double calAverage(int*, int);
double calStanD(int*, int, double);
double calLow(int, double, double);
double calHigh(int, double, double);

int main()
{
  // Local Declarations
  int nums[ARRSIZE]; // ARRAY OF SIZE 10000
  int seed; // VALUE OF THE SEED
  int firstLim; // FIRST LIMIT RANGE
  int secondLim; // SECOND LIMIT RANGE
  double average; // AVERAGE OF THE NUMBERS
  double stdDev; // STANDARD DEVIATION OF THE NUMBERS
  double ciLow; // LOWER INTERVAL OF CONFIDENCE INTERVAL
  double ciHigh; // HIGHER INTERVAL OF CONFIDENCE INTERVAL

  // Executable Statements
  seed = askInformation(1, 0);
  firstLim = askInformation(2, 0);
  secondLim = askInformation(3, firstLim);

  srand(seed);

  generateValues(nums);

  average = calAverage(nums, firstLim);
  stdDev = calStanD(nums, firstLim, average);
  ciLow = calLow(firstLim, average, stdDev);
  ciHigh = calHigh(firstLim, average, stdDev);
  printResults(firstLim, average, stdDev, ciLow, ciHigh);

  average = calAverage(nums, secondLim);
  stdDev = calStanD(nums, secondLim, average);
  ciLow = calLow(secondLim, average, stdDev);
  ciHigh = calHigh(secondLim, average, stdDev);
  printResults(secondLim, average, stdDev, ciLow, ciHigh);

  average = calAverage(nums, ARRSIZE);
  stdDev = calStanD(nums, ARRSIZE, average);
  ciLow = calLow(ARRSIZE, average, stdDev);
  ciHigh = calHigh(ARRSIZE, average, stdDev);
  printResults(ARRSIZE, average, stdDev, ciLow, ciHigh);
  return 0;
}
/*****+-*-*-***--*---********-*--*---*---**-********************************
*
*  Function Information
*
*  Name of Function: printResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int limit - Limit of the data
*    2. double average - Average of the data set
*    3. double stdDev - standard deviation of the data set
*    4. double ciLow - low confidence interval
*    5. double ciHigh - high confidence interval
*  Function Description: This function prints out the results of the calculations for each range
*
******+-*-*-***--*---********-*--*---*---**-*******************************/
void printResults(int limit, double average, double stdDev, double ciLow, double ciHigh)
{
  printf("\nNumber: %d", limit);
  printf("\nAverage: %.2lf", average);
  printf("\nStandard deviation: %.2lf", stdDev);
  printf("\nConfidence Interval: %.2lf, %.2lf\n", ciLow, ciHigh);
}
/*****+---*-***--*---********-*--*---*---**-********************************
*
*  Function Information
*
*  Name of Function: generateValues
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int nums[] - the array of size 10000
*
*  Function Description: This function generates the random values for each index in the array and maps it to the specific range
*
******+---*-***--*---********-*--*---*---**-*******************************/
void generateValues(int nums[])
{
  // Local Declarations
  int i; // ITERATING INDEX

  // Executable Statements
  for(i = 0; i < ARRSIZE; i++)
  {
    nums[i] = rand() % 100 + 1;
  }
}
/*****+-*---***--*---********-*--*---*---**-********************************
*
*  Function Information
*
*  Name of Function: askInformation
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int option - The option of which statement to print out
*    2. int firstValue - The value of the first range limit for the bounds on the second range limit
*
*  Function Description: This function asks the user to input information and validates their values to be within the specified range.
*
******+-*---***--*---********-*--*---*---**-*******************************/
int askInformation(int option, int firstValue)
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
    printf("Enter first range limit -> ");
    scanf("%d", &info);
    if(info <= 0 || info > 5000)
    {
      do
      {
        if(info <= 0)
        {
          printf("\nError! First limit size minimum is one! \n");
          printf("\nEnter first range limit -> ");
          scanf("%d", &info);
        }
        else
        {
          printf("\nError! First limit size maximum is 5000\n");
          printf("\nEnter first range limit -> ");
          scanf("%d", &info);
        }
      } while(info <= 0 || info > 5000);
    }
  }
  
  if(option == 3)
  {
    printf("Enter second range limit -> ");
    scanf("%d", &info);
    if(info > 10000 || info == firstValue)
    {
      do
      {
        if(info > 10000)
        {
          printf("\nError! Second limit value must be < 10000\n");
          printf("\nEnter second range limit -> ");
          scanf("%d", &info);
        }
        else
        {
          printf("\nError! Second limit value must be > %d\n", firstValue);
          printf("\nEnter second range limit -> ");
          scanf("%d", &info);
        }
      } while(info > 10000 || info == firstValue);
    }
  }
  return info;
}
/*****+---*--**--*---********-*--*---*---**-********************************
*
*  Function Information
*
*  Name of Function: calAverage
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int a[] - The array in the main that has all the values passed to directly access all the values and iterate in this function
*    2. int datasize - The number of times the for-loop should run and the number of values to divide the sum by.
*
*  Function Description: this function calculates the average of the numbers in the data set
*
******+---*--**--*---********-*--*---*---**-*******************************/
double calAverage(int a[],int datasize)
{
  // local declarations
  double sum; // Sum of values added to find the average
  double Avg; // Average of the values
  int i; // Iterating index

  // executable statements
  sum = 0;
  for(i = 0; i < datasize; i++)
  {
    sum = sum + a[i];
  }
  Avg = sum / datasize ;
  return Avg;
}
/*****+-*-*-**---*---********-*--*---*---**-********************************
*
*  Function Information
*
*  Name of Function: calStanD
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int a[] - Original array in the main that is passed by address to be accessed directly
*    2. int datasize - the range of the data for the standard deviation to be found for
*    3. double Avg - the average of the data set calculated prior
*
*  Function Description: This function calculates the standard deviation using the given formula
*
******+-*-*-**---*---********-*--*---*---**-*******************************/
double calStanD(int a[],int datasize, double  Avg)
{
  // local declarations
  double stan; // Standard deviation that will be calculated
  double sum; // sum of the numbers in the data set
  int i; // iterating index

  // executable statements
  sum = 0;
  for(i = 0; i < datasize; i++)
  {
    sum = sum + pow((a[i] - Avg), 2);
  }

  stan = sqrt(sum / datasize);
  return stan;
}
/*****+---*-**---*---********-*--*---*---**-********************************
*
*  Function Information
*
*  Name of Function: calLow
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int datasize - range of the data for the lower bound to be found
*    2. double Avg - average of the numbers of the data set
*    3. double stan - standard deviation of the numbers of the data set
*
*  Function Description: this function finds the lower bound of the confidence interval with the given formula
*
******+---*-**---*---********-*--*---*---**-*******************************/
double calLow(int datasize, double Avg, double stan)
{
  // local declarations
  double LOW; // Lower bound of the confidence interval

  // executable statements
  LOW = Avg - 1.96 * stan / sqrt(datasize);
  return LOW;
}
/*****+-----**---*---********-*--*---*---**-********************************
*
*  Function Information
*
*  Name of Function: calHigh
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int datasize - range of the data for the higher bound to be found for
*    2. doube Avg - average of the numbers in the data set
*    3. double stan - Standard deviation of the numbers in the data set
*
*  Function Description: this function finds the upper bound of the confidence interval with the given formula.
*
******+-----**---*---********-*--*---*---**-*******************************/
double calHigh(int datasize, double Avg, double stan)
{
  // local declarations
  double High; // higher bound of the confidence interval

  // executable statements
  High = Avg + 1.96 * stan / sqrt(datasize);
  return High;
}