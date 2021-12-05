#include<stdio.h>
#include<math.h>

#define MIDTERMWEIGHT 0.2 // WEIGHT OF EACH MIDTERM
#define FINALEXAMWEIGHT 0.6 // WEIGHT OF THE FINAL EXAM

// FUNCTION DECLARATIONS
double askScore(double);
double calcAverage(double, double, double, double);
void printResults(double);

int main()
{
  // LOCAL DECLARATIONS
  double score1; // FIRST MIDTERM SCORE
  double score2; // SECOND MIDTERM SCORE
  double score3; // THIRD MIDTERM SCORE
  double final; // FINAL EXAM SCORE
  double courseAverage; // AVERAGE OF THE SCORES IN THE CLASS

  // EXECUTABLE STATEMENTS
  score1 = askScore(1);
  score2 = askScore(2);
  score3 = askScore(3);
  final = askScore(4);
  courseAverage = calcAverage(score1, score2, score3, final);

  printResults(courseAverage);

  return 0;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: askScore
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double choice - Determines which score is asked to be inputted by the user
*
*  Function Description: This function uses the choice parameter to check which statement to print and ask the user for that score before returning that inputted score. 
*
***************************************************************************/

double askScore(double choice)
{
  // LOCAL DECLARATIONS
  double score; // SCORE THAT WILL HOLD THE USER-INPUTTED SCORE

  // EXECUTABLE STATEMENTS
  if(choice == 1)
  {
    printf("Enter midterm #1 score -> ");
    scanf("%lf", &score);
  }
  else if(choice == 2)
  {
    printf("Enter midterm #2 score -> ");
    scanf("%lf", &score);
  }
  else if(choice == 3)
  {
    printf("Enter midterm #3 score -> ");
    scanf("%lf", &score);
  }
  else
  {
    printf("Enter final exam score -> ");
    scanf("%lf", &score);
  }

  return score;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcAverage
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double score1 - The score of the first midterm that the user inputted
*    2. double score2 - The score of the second midterm that the user inputted
*    3. double score3 - The score of the third midterm that the user inputted
*    4. double final -  The score of the final that the user inputted
*
*  Function Description: This function uses the lowScore variable to check what is the lowest score and set it to 0.0 to drop it. It then returns the course average by adding the midterm scores and multiplying them by the weight and adding the final multiplied by its weight. 
*
***************************************************************************/

double calcAverage(double score1, double score2, double score3, double final)
{
  // LOCAL DECLARATIONS
  double lowScore; // VARIABLE TO COMPARE AND FIND THE LOWEST SCORE

  // EXECUTABLE STATEMENTS
  lowScore = score1;
  if(lowScore > score2)
  {
    lowScore = score2;
  }
  if(lowScore > score3)
  {
    lowScore = score3;
  }
  if(lowScore == score1)
  {
    score1 = 0.0;
  }
  else if(lowScore == score2)
  {
    score2 = 0.0;
  }
  else
  {
    score3 = 0.0;
  }

  return (score1 + score2 + score3) * MIDTERMWEIGHT + final * FINALEXAMWEIGHT;
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
*    1. double courseAverage - The calculated course average from the calcAverage() function
*
*  Function Description: This function prints the course average and the corresponding letter grade by comparing the courseAverage variable to the scores table and printing out the right statement. Before it does that, it rounds the courseAverage to two decimal places and checks to see if the ending rounded up from an even to an odd and undoes that rounding. 
*
***************************************************************************/
void printResults(double courseAverage)
{
  // EXECUTABLE STATEMENTS
  courseAverage = round(courseAverage * 100) / 100.0; // ROUNDING FOR CASES LIKE EXAMPLE #7
  if((int)(courseAverage * 100) % 2 == 1) // CHECKING TO SEE IF THE ROUND LED TO AN EVEN TO UNDO THE ROUND
  {
    courseAverage -= 0.01;
  }
  printf("\nCourse Average: %.2lf", courseAverage);

  if(courseAverage >= 98)
  {
    printf("\nGrade Earned: A+\n");
  }
  else if(courseAverage > 92)
  {
    printf("\nGrade Earned: A\n");
  }
  else if(courseAverage >= 90)
  {
    printf("\nGrade Earned: A-\n");
  }
  else if(courseAverage >= 88)
  {
    printf("\nGrade Earned: B+\n");
  }
  else if(courseAverage >= 82)
  {
    printf("\nGrade Earned: B\n");
  }
  else if(courseAverage >= 80)
  {
    printf("\nGrade Earned: B-\n");
  }
  else if(courseAverage >= 78)
  {
    printf("\nGrade Earned: C+\n");
  }
  else if(courseAverage >= 72)
  {
    printf("\nGrade Earned: C\n");
  }
  else if(courseAverage >= 70)
  {
    printf("\nGrade Earned: C-\n");
  }
  else if(courseAverage >= 68)
  {
    printf("\nGrade Earned: D+\n");
  }
  else if(courseAverage >= 62)
  {
    printf("\nGrade Earned: D\n");
  }
  else if(courseAverage >= 60)
  {
    printf("\nGrade Earned: D-\n");
  }
  else
  {
    printf("\nGrade Earned: F\n");
  }
}