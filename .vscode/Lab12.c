#include<stdio.h>
#include<stdlib.h>

// Function Declarations
void bubbleSort(int*, int, int, int*);
int askSeed();
int askDataSize();
int askMaxValue();
void generateValues(int*, int, int);
void math(int*, int*, int);
void printResults(int*, int);
int main()
{
  // Local Declarations
  int seed;
  int dataSize;
  int maxValue;
  int *nums;
  int *counts;

  // Executable Statements
  seed = askSeed();
  srand(seed);

  dataSize = askDataSize();
  maxValue = askMaxValue();
  nums = malloc(sizeof(int) * dataSize);
  counts = malloc(sizeof(int) * dataSize);
  generateValues(nums, dataSize, maxValue);

  math(nums, counts, dataSize);
  bubbleSort(nums, dataSize, 0, counts);

  printResults(nums, dataSize);
  return 0;
}
void printResults(int nums[], int dataSize)
{
  // Local Declarations
  int i;
  // Executable Statements
  printf("\nData sorted by +1 count: ");
  for(i = 0; i < dataSize; i++)
  {
    printf("%d ", nums[i]);
  }
  printf("\n");
}
void math(int nums[], int counts[], int dataSize)
{
  // Local Declarations
  int i;
  int count;
  int temp;

  // Executable Statements
  for(i = 0; i < dataSize; i++)
  {
    count = 0;
    temp = nums[i];
    while(temp != 1)
    {
      if(temp % 7 == 0)
      {
        temp = temp / 7;
      }
      else
      {
        temp = temp + 1;
        count++;
      }
    }
    counts[i] = count;
  }
}
void bubbleSort(int nums[], int end, int start, int counts[])
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
      if(counts[j] > counts[j + 1])
      {
        temp = counts[j];
        counts[j] = counts[j + 1];
        counts[j + 1] = temp;

        temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;

      }
      if(nums[j] > nums[j + 1] && counts[j] == counts[j + 1])
      {
        temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
      }
    }
  }
}
void generateValues(int nums[], int dataSize, int maxValue)
{
  // Local Declarations
  int i;

  // Executable Statements
  for(i = 0; i < dataSize; i++)
  {
    nums[i] = rand() % maxValue + 1;
  }
}
int askSeed()
{
  // Local Declarations
  int seed;

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
int askDataSize()
{
  // Local Declarations
  int dataSize;

  // Executable Statements
  do
  {
    printf("Enter data set size -> ");
    scanf("%d", &dataSize);

    if(dataSize <= 0)
    {
      printf("\nError! Size must be a positive integer value!!\n\n");
    }
  } while(dataSize <= 0);

  return dataSize;
}
int askMaxValue()
{
  // Local Declarations
  int max;

  // Executable Statements
   do
  {
    printf("Enter max value to generate -> ");
    scanf("%d", &max);

    if(max <= 0)
    {
      printf("\nError! Maximum value must be a positive integer!!\n\n");
    }
  } while(max <= 0);
  return max;
}