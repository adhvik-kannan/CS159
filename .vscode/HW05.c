#include<stdio.h>

#define TENTHOU 10000 // TEN THOUSAND CONVERSION NUMBER
#define DAYCONVERSION 100 % 100 // CONVERTING THE DATE GIVEN INTO THE DAY
#define YEARCONVERSION 100 + 2000 // CONVERTING THE DATE GIVEN INTO THE YEAR

// FUNCTIONS DECLARATIONS
int askInformation(int);
int checkAppt(int, int, int);
int calculateSecondAppt(int, int, int);
int createOtherFamAppts(int, int, int);
void printResults(int, int, int, int, int, int, int);

int main()
{
  // LOCAL DECLARATIONS
  int numFam; // NUMBER OF FAMILY MEMBERS
  int date1; // DATE OF APPOINTMENT ONE
  int date2; // DATE OF APPOINTMENT TWO
  int i; // VARIABLE FOR ITERATING THROUGH THE FOR-LOOP

  // EXECUTABLE STATEMENTS
  numFam = askInformation(1);
  date1 = askInformation(2);

  for(i = 1; i <= numFam; i++)
  {
    date1 = checkAppt(date1 / TENTHOU, date1 / DAYCONVERSION, date1 % YEARCONVERSION);
    date2 = calculateSecondAppt(date1 / TENTHOU, date1 / DAYCONVERSION, date1 % YEARCONVERSION);
    date2 = checkAppt(date2 / TENTHOU, date2 / DAYCONVERSION, date2 % YEARCONVERSION);

    printResults(date1 / TENTHOU, date1 / DAYCONVERSION, date1 % 100, date2 / TENTHOU, date2 / DAYCONVERSION, date2 % 100, i);

    date1 = createOtherFamAppts(date1 / TENTHOU, date1 / DAYCONVERSION, date1 % YEARCONVERSION);
    date1 = checkAppt(date1 / TENTHOU, date1 / DAYCONVERSION, date1 % YEARCONVERSION);
    date2 = calculateSecondAppt(date1 / TENTHOU, date1 / DAYCONVERSION, date1 % YEARCONVERSION);
    date2 = checkAppt(date2 / TENTHOU, date2 / DAYCONVERSION, date2 % YEARCONVERSION);
  }
  
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
*    1. int month1 - The month from the date of the first appointment
*    2. int day1 - The day from the date of the first appointment
*    3. int year1 - The year from the date of the first appointment
*    4. int month2 - The month from the date of the second appointment
*    5. int day2 - The day from the date of the second appointment
*    6. int year2 - The year from the date of the second appointment
*    7. int i - The value of which iteration the for-loop is on
*
*  Function Description: This function prints the first appointment and second appointment for each family. 
*
***************************************************************************/

void printResults(int month1, int day1, int year1, int month2, int day2, int year2, int i)
{
  // EXECUTABLE STATEMENTS
  if(i == 1)
  {
    printf("\n<-=-=-=-=-=-=-=-> Appt. #1 -- Appt. #2\n");
  }
  printf("Family member #%d: %02d/%02d/%02d -- %02d/%02d/%02d\n", i, month1, day1, year1, month2, day2, year2);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: createOtherFamAppts
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int month - The month of the first appointment of the previous family member
*    2. int day - The day of the first appointment of the previous family member
*    3. int year - The year of the first appointment of the previous family member
*
*  Function Description: This function uses switch-cases to determine the amount of days in the month chosen in order to determine how to find the day of the first  appointment and what to do when the month changes. It also accounts for leap years and returns the day as one number for the family members.
*
***************************************************************************/

int createOtherFamAppts(int month, int day, int year)
{
  // LOCAL DECLARATIONS
  int num; // ID KEY TO IDENTIFY THE MONTH THAT HAS 31, 30, or 28/29 DAYS

  // EXECUTABLE STATEMENTS
  switch(month)
  {
     case 1 :
     case 3 :
     case 5 :
     case 7 :
     case 8 :
     case 10:
     case 12: num = 1;
              break;
     case 2 : num = 2;
              break;
     case 4 :
     case 6 :
     case 9 :
     case 11: num = 0;
              break;
  }

  if(num == 0)
  {
    if(day + 10 > 30)
    {
      day -= 20;
      month++;
    }
    else
    {
      day += 10;
    }
  }
  else if(num == 1)
  {
    if(day + 10 > 31)
    {
      day -= 21;
      if(month == 12)
      {
        month = 1;
        year++;
      }
      else
      {
        month++;
      }
    }
    else
    {
      day += 10;
    }
  }
  else
  {
    if((!(year % 4) && (year % 100)) || !(year % 400))
    {
      if(day + 10 > 29)
      {
        month++;
        day -= 19;
      }
      else
      {
        day += 10;
      }
    }
    else
    {
      if(day + 10 > 28)
      {
        day -= 18;
        month++;
      }
      else
      {
        day += 10;
      }
    }
  }
  return month * 10000 + day * 100 + (year % 100);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: calculateSecondAppt
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int month - The month of the first appointment
*    2. int day - The day of the first appointment
*    3. int year - The year of the first appointment
*
*  Function Description: This function finds the second appointment based on the rules and the first appointment. It uses the checkAppt() function to make sure that the appointment doesn't fall on a Sunday.
*
***************************************************************************/

int calculateSecondAppt(int month, int day, int year)
{
  // LOCAL DECLARATIONS
  int date; // DATE OF THE SECOND APPOINTMENT

  // EXECUTABLE STATEMENTS
  if(month == 12)
  {
    month = 2;
    year++;
  }
  else if(month == 11)
  {
    month = 1;
    year++;
  }
  else
  {
    month += 2;
  } 
  date  = checkAppt(month, day, year);

  return date;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: checkAppt
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int month - The month of the date
*    2. int day - The day of the date
*    3. int year - The year of the date
*
*  Function Description: This function determines what the day of the week the date falls on and makes sure it follows the rule that no appointments are on Sundays. It returns the date, even if it isn't modified. 
*
***************************************************************************/
int checkAppt(int month, int day, int year)
{
  // LOCAL DECLARATIONS
  int num; // COMBINATION OF ALL THE DAYS BEFORE THE MONTH, THE KEY OF THE DAY OF THE WEEK THAT PREVIOUS YEAR'S DECEMBER 31st
  int daysInFeb; // DAYS IN FEBRUARY THAT CHANGES BASED ON WHETHER IT IS A LEAP YEAR OR NOT
  int dayOfWeek; // THE DAY OF THE WEEK THAT THE WANTED DATE FALLS ON
  // EXECUTABLE STATEMENTS
  num = ((year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;
  if((!(year % 4) && (year % 100)) || !(year % 400))
  {
    daysInFeb = 29;
  }
  else
  {
    daysInFeb = 28;
  }
  switch(month)
  {
     case 12: num += 31 + daysInFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
              break;
     case 11: num += 31 + daysInFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
              break;
     case 10: num += 31 + daysInFeb + 31 + 30 + 31 + 30 + 31 + 31 + 30;
              break;
     case 9:  num += 31 + daysInFeb + 31 + 30 + 31 + 30 + 31 + 31;
              break;
     case 8:  num += 31 + daysInFeb + 31 + 30 + 31 + 30 + 31;
              break;
     case 7:  num += 31 + daysInFeb + 31 + 30 + 31 + 30;
              break;
     case 6:  num += 31 + daysInFeb + 31 + 30 + 31;
              break;
     case 5:  num += 31 + daysInFeb + 31 + 30;
              break;
     case 4:  num += 31 + daysInFeb + 31;
              break;
     case 3:  num += 31 + daysInFeb;
              break;
     case 2:  num += 31;
              break;
  }
  dayOfWeek = (day + num) % 7;
  if(dayOfWeek == 0)
  {
    dayOfWeek++;
    if(day == 31)
    {
      day = 1;
      if(month == 12)
      {
        month = 1;
        year++;
      }
      else
      {
        month++;
      }

    }
    else
    {
      day++;
    }
  }

  return month * 10000 + day * 100 + (year % 100);
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: askInformation
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int option - A key to determine which print statement to print
*
*  Function Description: This function asks the user for the information that is used in the rest of the program. Based on the key (that the programmer enters in order to prompt which question), the respective information is returned. 
*
***************************************************************************/

int askInformation(int option)
{
  // LOCAL DECLARATIONS
  int info; // INFORMATION EITHER ABOUT NUMBER OF FAMILY MEMBERS OR FIRST DATE

  // EXECUTABLE STATEMENTS
  if(option == 1)
  {
    printf("Enter number of family members -> ");
    scanf("%d", &info);
  }
  else
  {
    printf("Enter date (MMDDYY) -> ");
    scanf("%d", &info);
  }

  return info;
}
