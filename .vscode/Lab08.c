#include<stdio.h>

// FUNCTION DECLARATIONS
int askDate();
int findMonth(int);
int findDay(int);
int findYear(int);
int findDayOfWeek(int, int, int);
void printHeader(int);
void printCalendar(int, int, int);

int main()
{
  // LOCAL DECLARATIONS
  int date;  // the date including year, month, and numbered day
  int dayOfWeek;   // the day of the date 
  int month; // the month of the date
  int day; // the numbered day of the date 
  int year; // the year of the date 

  // EXECUTABLE STATEMENTS
  date = askDate();
  month = findMonth(date);
  day = findDay(date);
  year = findYear(date);
  dayOfWeek = findDayOfWeek(month, day, year);
  printHeader(dayOfWeek);
  printCalendar(day, month, year);

  return 0;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: printCalendar
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int day - the numerical day of the date given
*    2. int month - the month of the date given 
*    3. int year - the year of the date given
*
*  Function Description: the purpose of this function is to print out a calendar that starts at a given date and end on the following month of the same day
*
***************************************************************************/
void printCalendar(int day, int month, int year)
{
  // LOCAL DECLARATIONS
  int num; // ID KEY TO IDENTIFY THE MONTH THAT HAS 31, 30, or 28/29 DAYS
  int i;   // the number of iterations 
  int week; // the week of the month 
  int count; // the slot on the calendar 

  // EXECUTABLE STATEMENTS
  week = 1;
  count = 1;
  switch(month)
  {
     case 1 :
     case 3 :
     case 5 :
     case 7 :
     case 8 :
     case 10:
     case 12: num = 31;
              break;
     case 2 : num = 2;
              break;
     case 4 :
     case 6 :
     case 9 :
     case 11: num = 30;
              break;

  }
  if(month == 2)
  {
    if((!(year % 4) && (year % 100)) || !(year % 400))
    {
      num = 29;
    }
    else
    {
      num = 28;
    }
  }
  for(i = day; i <= num; i++)
  {
    if(count == 1)
    {
      printf("Week %d:", week);
    }
    if(count == 7)
    {
      printf(" %3d", i);
      week++;
      count = 1;
      printf("\n");
    }
    else
    {
      printf(" %3d", i);
      count++;
    }
  } if(day == 31)
  {
    if(month == 1)
    {
      day = 28;
    }
    else
    {
      day = 30;
    }
  }
  for(i = 1; i <= day; i++)
  {

    if(count == 1)
    {
      printf("Week %d:", week);
    }
    if(count == 7)
    {
      printf(" %3d", i);
      week++;
      count = 1;
      printf("\n");
    }
    else
    {
      printf(" %3d", i);
      count++;
    }
  }
  printf("\n");
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: findMonth
*
*  Function Return Type: int 
*
*  Parameters (list data type, name, and comment one per line):
*    1. int date - the date given by user
*
*  Function Description: the purpose if this function is to extract the month from the date given 
*
***************************************************************************/

int findMonth(int date)
{
  return date / 10000;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: findDay
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int date - the date the user has given 
*
*  Function Description: the purpose of this function is to extract he day from the date given 
*
***************************************************************************/

int findDay(int date)
{
  return date / 100 % 100;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: findYear
*
*  Function Return Type: int 
*
*  Parameters (list data type, name, and comment one per line):
*    1. int date - the date that the user has given 
*
*  Function Description: the purpose of this function is to extract the year from the date given 
*
***************************************************************************/
int findYear(int date)
{
  return date % 100 + 2000;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: printHeader 
*
*  Function Return Type: void 
*
*  Parameters (list data type, name, and comment one per line):
*    1. int dayOfWeek - the weekday that the given date is 
*
*  Function Description: the purpose of this function is to figure out what day the calendar starts at given the first day of the week from the date given and then print the corresponding header that is required 
*
***************************************************************************/
void printHeader(int dayOfWeek)
{
  if(dayOfWeek == 0)
  {
    printf("\nHeader: Sun Mon Tue Wed Thu Fri Sat\n");
  }
  if(dayOfWeek == 1)
  {
    printf("\nHeader: Mon Tue Wed Thu Fri Sat Sun\n");
  }
  if(dayOfWeek == 2)
  {
    printf("\nHeader: Tue Wed Thu Fri Sat Sun Mon\n");
  }
  if(dayOfWeek == 3)
  {
    printf("\nHeader: Wed Thu Fri Sat Sun Mon Tue\n");
  }

  if(dayOfWeek == 4)
  {
    printf("\nHeader: Thu Fri Sat Sun Mon Tue Wed\n");
  }
  if(dayOfWeek == 5)
  {
    printf("\nHeader: Fri Sat Sun Mon Tue Wed Thu\n");
  }

  if(dayOfWeek == 6)
  {
    printf("\nHeader: Sat Sun Mon Tue Wed Thu Fri\n");
  }
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: askDate
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line): N/A
*
*  Function Description: this function is meant to get a date that the user wants to print a calendar for 
*
***************************************************************************/

int askDate()
{
  // LOCAL DECLARATIONS
  int date; // the date that the user wants us to start the calendar at 

  // EXECUTABLE STATEMENTS
  printf("Enter date (MMDDYY) -> ");
  scanf("%d", &date);
  return date;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: findDayOfWeek
*
*  Function Return Type: int 
*
*  Parameters (list data type, name, and comment one per line):
*    1. int month - the month of the given date
*    2. int day - the day of the given date
*    3. int year - the year of the given date
*
*  Function Description: the purpose of this function is to find the weekday that the given date is on by first finding the weekday of the last day of the previous year and adding up every other day until you reach the given
*  date 
*
***************************************************************************/
int findDayOfWeek(int month, int day, int year)
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
  }

  dayOfWeek = (day + num) % 7;

  return dayOfWeek;
}