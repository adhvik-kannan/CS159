#include<stdio.h>
#include<math.h>

#define RADTODEGREES 180 / M_PI // CONVERSION FROM RADIANS TO DEGREES

// FUNCTION DECLARATIONS
int printDirections();
void askCoordinates(int, double*, double*, double*, double*, double*, double*);
double calculateAngle(int, double, double, double, double, double, double);
void printResults(double);

int main()
{
  // LOCAL DECLARATIONS
  int option; // OPTION CHOSEN BY USER
  double first; // FIRST DIGIT ENTERED BY USER -- THE FIRST X-COORDINATE
  double second; // SECOND DIGIT ENTERED BY USER -- THE FIRST Y-COORDINATE
  double third; // THIRD DIGIT ENTERED BY USER -- THE SECOND X-COORDINATE
  double fourth; // FOURTH DIGIT ENTERED BY USER -- THE SECOND Y-COORDINATE
  double fifth; // FIFTH DIGIT ENTERED BY USER -- THE THIRD X-COORDINATE
  double sixth; // SIXTH DIGIT ENTERED BY USER -- THE THIRD Y-COORDINATE
  double angle; // THE ANGLE THAT IS BEING LOOKED FOR

  // EXECUTABLE STATEMENTS
  option = printDirections();
  askCoordinates(option, &first, &second, &third, &fourth, &fifth, &sixth);
  angle = calculateAngle(option, first, second, third, fourth, fifth, sixth);
  printResults(angle);
  return 0;
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
*    1. double angle - The calculated angle that the user wants to be found
*
*  Function Description: This function prints the results of the calculations. It checks to see if the triangle was possible by checking if the angle was set to 0 by the calculateAngle function as an angle cannot be 0 in any triangle. If it is 0, the function prints an error statement. Otherwise, it prints the desired angle. 
*
***************************************************************************/

void printResults(double angle)
{
  if(angle == 0)
  {
    printf("\nError: Coordinates given do not create a right triangle!\n");
  }
  else
  {
    printf("\nThe desired angle within the right triangle: %.1lf\n", angle);
  }
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: calculateAngle
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. int option - The option chosen by the user
*    2. double first - The first x-coordinate
*    3. double second - The first y-coordinate
*    4. double third - The second x-coordinate
*    5. double fourth - The second y-coordinate
*    6. double fifth - The third x-coordinate
*    7. double sixth - The third y-coordinate
*
*  Function Description: This function calculates the angle that is being looked for based on the user's chosen option. It uses if-statements to determine the option and then calculates the appropriate sides and checks to see if the triangle is a right triangle. If the triangle is not a right triangle, the function sets the angle to 0.0 as it is not possible for a triangle to have an angle of 0. It then calculates the angle based on the correct sides and returns the angle that the user wanted found. 
*
***************************************************************************/
double calculateAngle(int option, double first, double second, double third, double fourth, double fifth, double sixth)
{
  // LOCAL DECLARATIONS
  double hyp; // HYPOTENUSE OF THE TRIANGLE -- EITHER GIVEN BY USER OR CALCULATED USING OTHER POINTS
  double adjacent; // ADJACENT OF THE ANGLE -- EITHER GIVEN BY USER OR CALCULATED USING OTHER POINTS
  double opposite; // OPPOSITE OF THE ANGLE -- EITHER GIVEN BY USER OR CALCULATED USING OTHER POINTS
  double angle; // ANGLE THAT IS BEING LOOKED FOR

  // EXECUTABLE STATEMENTS
  if(option == 1)
  {
    opposite = sqrt(pow(third - fifth, 2) + pow(fourth - sixth, 2));
    adjacent = sqrt(pow(first - fifth, 2) + pow(second - sixth, 2));
    hyp = sqrt(pow(first - third, 2) + pow(second - fourth, 2));

    if(pow(hyp, 2) - (pow(opposite, 2) + pow(adjacent, 2)) > 0.001)
    {
      angle = 0.0;
    }
    else
    {
      angle = asin(opposite / hyp) * RADTODEGREES;
    }
  }
  else if(option == 2)
  {
    adjacent = sqrt(pow(third - fifth, 2) + pow(fourth - sixth, 2));
    opposite = sqrt(pow(first - fifth, 2) + pow(second - sixth, 2));
    hyp = sqrt(pow(first - third, 2) + pow(second - fourth, 2));

    if(pow(hyp, 2) - (pow(opposite, 2) + pow(adjacent, 2)) > 0.001)
    {
      angle = 0.0;
    }
    else
    {
      angle = acos(adjacent / hyp) * RADTODEGREES;
    }
  }
  else
  {
    opposite = sqrt(pow(first - third, 2) + pow(second - fourth, 2));
    adjacent = sqrt(pow(third - fifth, 2) + pow(fourth - sixth, 2));
    hyp = sqrt(pow(first - fifth, 2) + pow(second - sixth, 2));

    if(pow(hyp, 2) - (pow(opposite, 2) + pow(adjacent, 2)) > 0.001)
    {
      angle = 0.0;
    }
    else
    {
      angle = atan(opposite / adjacent) * RADTODEGREES;
    }
  }
  return angle;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: printDirections
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line): NONE
*
*  Function Description: This function prints the initial directions of what are the possible options and prompts the user to enter which option they would like to be used. The function returns this option. 
*
***************************************************************************/

int printDirections()
{
  // LOCAL DECLARATIONS
  int option; // THE OPTION THAT THE USER ENTERS

  // EXECUTABLE STATEMENTS
  printf("Please select the sides required to calculate angle from the options below.");
  printf("\n1. Hypotenuse and opposite sides");
  printf("\n2. Hypotenuse and adjacent sides");
  printf("\n3. Opposite side and adjacent sides\n");

  printf("\nEnter desired option -> ");
  scanf("%d", &option);
  return option;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: askCoordinates
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int option - The option that the user entered for which angle they want to find
*    2. double *first - Pointer to directly change the first x-coordinate
*    3. double *second - Pointer to directly change the first y-coordinate
*    4. double *third - Pointer to directly change the second x-coordinate
*    5. double *fourth - Pointer to directly change the second y-coordinate
*    6. double *fifth - Pointer to directly change the third x-coordinate
*    7. double *sixth - Pointer to directly change the third y-coordinate
*
*  Function Description: This function uses the selected option to determine which set of phrases to ask. The function then uses pointers and pass by address to directly change the variables in order to save all the points. It does this to have the coordinates of the triangle that the user wants and to help the calculation of the angle the user is looking for.
*
***************************************************************************/
void askCoordinates(int option, double *first, double *second, double *third, double *fourth, double *fifth, double *sixth)
{
  // EXECUTABLE STATEMENTS
  if(option == 1)
  {
    printf("Enter endpoint coordinates for hypotenuse -> ");
    scanf("%lf %lf %lf  %lf", first, second, third, fourth);
    printf("Enter terminal coordinates for opposite side [%.1lf, %.1lf] -> ", *third, *fourth);
    scanf("%lf %lf", fifth, sixth);
  }
  else if(option == 2)
  {
    printf("Enter endpoint coordinates for hypotenuse -> ");
    scanf("%lf %lf %lf  %lf", first, second, third, fourth);
    printf("Enter terminal coordinates for adjacent side [%.1lf, %.1lf] -> ", *third, *fourth);
    scanf("%lf %lf", fifth, sixth);
  }
  else
  {
    printf("Enter endpoint coordinates for opposite side -> ");
    scanf("%lf %lf %lf %lf", first, second, third, fourth);
    printf("Enter terminal coordinates for adjacent side [%.1lf, %.1lf] -> ", *third, *fourth);
    scanf("%lf %lf", fifth, sixth);
  }
}