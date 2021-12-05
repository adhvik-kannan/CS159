#include<stdio.h>

#define CONNECTIONCHARGE 10.54 //connection charge 
#define FIRSTCHARGE 0.14 // first level of charge rate
#define SECONDCHARGE 0.10 // second level of charge rate
#define OVERCHARGE 0.09 // third level of charge rate
#define MAXCHARGE 2000.00 // maximum electrical charge 

// FUNCTION DECLARATIONS
double askUsage();
void printResults(double, double, double, double);
double calFirstCharge(double);
double calSecondCharge(double);
double calThirdCharge(double);
double calTotal(double, double, double);

int main()
{
  // LOCAL DECLARATIONS
  double usage; // usage of electricity 
  double firstCharge; // electricity charge when usage is between 0 to 300kW
  double secondCharge; // electricity charge when usage is between 300 to 700 kW
  double thirdCharge; // electricity charge when usage is between 700kW to 1000kW 
  double total; // total electricity charge 

  // EXECUTABLE STATEMENTS
  usage = askUsage();
  firstCharge = calFirstCharge(usage);
  secondCharge = calSecondCharge(usage - 300);
  thirdCharge = calThirdCharge(usage - 1000);
  total = calTotal(firstCharge, secondCharge, thirdCharge);
  printResults(firstCharge, secondCharge, thirdCharge, total);

  return 0;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: calFirstCharge 
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, usage, the usage of electricity 
*
*  Function Description: the price of electricity when usage of electricity below 300kW
*
***************************************************************************/

double calFirstCharge(double usage)
{
  // Local Declarations
  double firstCharge; //first level electricity charge

  // Executable Statements
  if(usage >= 300)
  {
    firstCharge = 42;
  }
  else
  {
    firstCharge = usage * 0.14;
  }
  return firstCharge;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: calSecondCharge 
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, usage, the usage of electricity 
*
*  Function Description: the price of electricity when usage of electricity below 700kW
*                         and above 300kW
***************************************************************************/

double calSecondCharge(double usage)
{
  // Local Declarations
  double secondCharge; //second level of electricity charge

  // Executable Statements
  if(usage >= 700)
  {
    secondCharge = 70;
  }
  else if(usage < 0)
  {
    secondCharge = 0;
  }
  else
  {
    secondCharge = usage * 0.1;
  }
  return secondCharge;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: calThirdCharge 
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, usage, the usage of electricity 
*
*  Function Description:the price of electricity when usage of electricity below 1000kW 
*                        and above 700kW
*
***************************************************************************/

double calThirdCharge(double usage)
{
  //local Declarations
  double thirdCharge; // third level of electricity charge 
  // Executable Statements
  if(usage < 0)
  {
    thirdCharge = 0;
  }
  else
  {
    thirdCharge = usage * 0.09;
  }
  return thirdCharge;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:double 
*
*  Function Return Type:calTotal
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, fc, first level of charge 
*    2.double,sc,second level of charge 
*    3.double,tc,third level of charge 
*
*  Function Description: calculate the total charge of electricity 
*
***************************************************************************/

double calTotal(double fc, double sc, double tc)
{
  // Local Declarations
  double total; // total electricity charge

  // Executable Statements
  total = fc + sc +  tc;
  return total;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function:askUsage 
*
*  Function Return Type:double 
*
*  Parameters (list data type, name, and comment one per line):
*    none
*
*  Function Description:get amount of usage of electricity from user 
*
***************************************************************************/

double askUsage()
{
  // LOCAL DECLARATIONS
  double usage; //usage of electricity 

  // EXECUTABLE STATEMENTS
  printf("Enter usage (kWh) -> ");
  scanf("%lf", &usage);
  return usage;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: printResults 
*
*  Function Return Type: Void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, firstCharge, total price of first level of charge 
*    2.double, secondCharge, total price of second level of charge
*    3.double, thirdCharge, total price of third level of charge
*    4.double, total, total price of charge 
*
*  Function Description: print calculated results in correct situations. 
*
***************************************************************************/
void printResults(double firstCharge, double secondCharge, double thirdCharge, double total)
{
 // EXECUTABLE STATEMENTS
  if(total >= 2000)
  {
    printf("\nMaximum charge for month: $ %.2lf\n", MAXCHARGE);
  }
  else
  {
    if(total <= 1000)
    {
      total += CONNECTIONCHARGE;
      printf("\nConnection Charge: $ %.2lf", CONNECTIONCHARGE);
    }
    if(firstCharge > 0)
    {
      printf("\nCharge at rate $ %.2lf: $ %.2lf", FIRSTCHARGE, firstCharge);
    }
    if(secondCharge > 0)
    {
      printf("\nCharge at rate $ %.2lf: $ %.2lf", SECONDCHARGE, secondCharge);
    }
    if(thirdCharge > 0)
    {
      printf("\nCharge at rate $ %.2lf: $ %.2lf", OVERCHARGE, thirdCharge);
    }
    printf("\n\nTotal charge for month: $ %.2lf\n", total);
  }