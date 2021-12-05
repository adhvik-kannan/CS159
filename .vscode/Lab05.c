#include<stdio.h>                                                                                                                                                   
#include<math.h>                                                                                                                                                    
                                                                                                                                                                    
#define DEG_TO_RAD (M_PI / 180)                                                                                                                                     
#define GRAVITY 9.8                                                                                                                                                 
                                                                                                                                                                    
// FUNCTION DECLARATIONS                                                                                                                                            
double askAngle(int);                                                                                                                                               
double askMass();                                                                                                                                                   
double askDist();                                                                                                                                                   
double getLength(double, double, double);                                                                                                                           
double getTension(double, double, double);                                                                                                                          
void printResults(double, double, double, double);                                                                                                                  
                                                                                                                                                                    
int main()                                                                                                                                                          
{                                                                                                                                                                   
  // LOCAL DECLARATIONS                                                                                                                                             
  double angle1;   // the angle between cable 1 and the horizontal                                                                                                  
  double angle2;   // the angle between cable 2 and the horizontal                                                                                                  
  double mass;     // the mass of the object being held up                                                                                                          
  double distance; // the distance between the two cables                                                                                                           
  double length1;  // the length of cable 1                                                                                                                         
  double length2;  // the length of cable 2                                                                                                                         
  double tension1; // the tension of cable 1                                                                                                                        
  double tension2; // the tension of cable 2                                                                                                                        
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  angle1 = askAngle(1);                                                                                                                                             
  angle2 = askAngle(2);                                                                                                                                             
  mass = askMass();                                                                                                                                                 
  distance = askDist();                                                                                                                                             
  length1 = getLength(angle2, angle1, distance);                                                                                                                    
  length2 = getLength(angle1, angle2, distance);                                                                                                                    
  tension2 = getTension(angle1, angle2, mass);                                                                                                                      
  tension1 = getTension(angle2, angle1, mass);                                                                                                                      
                                                                                                                                                                    
  printResults(length1, tension1, length2, tension2);                                                                                                               
                                                                                                                                                                    
  return 0;                                                                                                                                                         
}                  
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: askAngle                                                                                                                                       
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line): N/A                                                                                                 
*                                                                                                                                                                   
*  Function Description: Read the angle that the users gives for the angle between the desired cable and horizontal.                                                
*                                                                                                                                                                   
***************************************************************************/                                                                                        
                                                                                                                                                                    
double askAngle(int number)                                                                                                                                         
{                                                                                                                                                                   
  // LOCAL DECLARATION                                                                                                                                              
  double angle; // the angle of the whichever cable is indicated                                                                                                    
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  printf("Enter angle #%d [degrees] -> ", number);                                                                                                                  
  scanf("%lf", &angle);                                                                                                                                             
  return angle;                                                                                                                                                     
}                                                                                                                                                                   
                                                                                                                                                                    
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: askMass                                                                                                                                        
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line): N/A                                                                                                 
*                                                                                                                                                                   
*  Function Description: Reads the mass that the users gives for the object being held up.                                                                          
*                                                                                                                                                                   
***************************************************************************/   
double askMass()                                                                                                                                                    
{                                                                                                                                                                   
  // LOCAL DECLARATIONS                                                                                                                                             
  double mass; // the mass of the object being held                                                                                                                 
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  printf("Enter mass of hanging object [kg] -> ");                                                                                                                  
  scanf("%lf", &mass);                                                                                                                                              
  return mass;                                                                                                                                                      
}                                                                                                                                                                   
                                                                                                                                                                    
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: askDist                                                                                                                                        
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line): N/A                                                                                                 
*                                                                                                                                                                   
*  Function Description: Reads the distance that the users gives for the distance between the cables                                                                
*                                                                                                                                                                   
***************************************************************************/                                                                                        
                                                                                                                                                                    
double askDist()                                                                                                                                                    
{                                                                                                                                                                   
  // LOCAL DECLARATIONS                                                                                                                                             
  double distance; // the distance between the cables                                                                                                               
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  printf("Enter distance between two posts [m] -> ");                                                                                                               
  scanf("%lf", &distance);                                                                                                                                          
  return distance;                                                                                                                                                  
}      
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: getLength                                                                                                                                      
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line):                                                                                                     
*    1. double angleA - the angle between the desired cable and the horizontal                                                                                      
*    2. double angleB - the angle between the other cable and the horizontal                                                                                        
*    3. double distD - the distance between the two cables                                                                                                          
*                                                                                                                                                                   
*  Function Description: this function calculates the length of the cable when given the angle between cable 1 and the horizontal, the angle between the cable      
*  and the horizontal and the distance between the two cables.                                                                                                      
*                                                                                                                                                                   
***************************************************************************/                                                                                        
                                                                                                                                                                    
double getLength(double angleA, double angleB, double distD)                                                                                                        
{                                                                                                                                                                   
  // LOCAL DECLARATIONS                                                                                                                                             
  double angleD; // the angle between cable 1 and cable 2                                                                                                           
  double distA;  // the length of the desired cable                                                                                                                 
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  angleD = 180 - (angleA + angleB);                                                                                                                                 
  distA = sin(angleA * DEG_TO_RAD) * distD / sin(angleD * DEG_TO_RAD);                                                                                              
  return distA;                                                                                                                                                     
}          
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: getTension                                                                                                                                     
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line):                                                                                                     
*    1. double angle1 - the angle between cable 1 and the horizontal                                                                                                
*    2. double angle2 - the angle between cable 2 and the horizontal                                                                                                
*    3. double mass - the mass of the object being held                                                                                                             
*                                                                                                                                                                   
*  Function Description: This function calculates the tension of the desired cable when given the angle between cable 1 and the horizontal                          
*  the angle between cable 2 and the horizontal and the mass of the object being held                                                                               
*                                                                                                                                                                   
***************************************************************************/                                                                                        
                                                                                                                                                                    
double getTension(double angle1, double angle2, double mass)                                                                                                        
{                                                                                                                                                                   
  // LOCAL DECLARATIONS                                                                                                                                             
  double tension;  // the tension of the desired cable                                                                                                              
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  tension = (mass * GRAVITY) / (tan(angle1 * DEG_TO_RAD) * cos(angle2 * DEG_TO_RAD) + sin(angle2 * DEG_TO_RAD));                                                    
  return tension;                                                                                                                                                   
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
*    1. double length1 - the length of cable 1                                                                                                                      
*    2. double tension1 - the tension of cable 1                                                                                                                    
*    3. double length2 - the length of cable 2                                                                                                                      
*    4. double tension2 - the tension of cable 2                                                                                                                    
*                                                                                                                                                                   
*  Function Description: Prints out the desired outcomes with a description for each value                                                                          
*                                                                                                                                                                   
***************************************************************************/                                                                                        
                                                                                                                                                                    
void printResults(double length1, double tension1, double length2, double tension2)                                                                                 
{                                                                                                                                                                   
  printf("\nLength of cable #1: %.2lf [m]", length1);                                                                                                               
  printf("\nTension of cable #1: %.2lf [N]\n", tension1);                                                                                                           
  printf("\nLength of cable #2: %.2lf [m]", length2);                                                                                                               
  printf("\nTension of cable #2: %.2lf [N]\n", tension2);                                                                                                           
