#include<stdio.h>                                                                                                                                                   
#include<math.h>                                                                                                                                                    
                                                                                                                                                                    
// FUNCTION DECLARATIONS                                                                                                                                            
double findLinearAccel(double, double);                                                                                                                             
double findAngularAccel(double, double);                                                                                                                            
double findAngularVel(double, double);                                                                                                                              
double findDistTraveled(double, double);                                                                                                                            
double findRevolutions(double, double);                                                                                                                             
double askVelocity();                                                                                                                                               
double askTime();                                                                                                                                                   
double askRadius();                                                                                                                                                 
void printResults(double, double, double, double, double);                                                                                                          
                                                                                                                                                                    
int main()                                                                                                                                                          
{                                                                                                                                                                   
  // LOCAL DECLARATIONS                                                                                                                                             
  double vehicleVelocity; // USER-GIVEN VELOCITY OF THE VEHICLE                                                                                                     
  double elapsedTime; // USER-GIVEN ELAPSED TIME TILL FINAL VELOCITY                                                                                                
  double radiusOfWheels; // USER-GIVEN RADIUS OF THE WHEELS                                                                                                         
  double linearAccel; // CALCULATED LINEAR ACCELERATION                                                                                                             
  double angularAccel; // CALCULATED ANGULAR ACCELERATION                                                                                                           
  double angularVelocity; // CALCULATED FINAL ANGULAR VELOCITY                                                                                                      
  double distTraveled; // CALCULATED DISTANCE TRAVELED BY THE VEHICLE                                                                                               
  double revolutions; // CALCULATED NUMBER OF REVOLUTIONS OF THE WHEELS                                                                                             
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  vehicleVelocity =  askVelocity();                                                                                                                                 
  elapsedTime = askTime();                                                                                                                                          
  radiusOfWheels = askRadius();                                                                                                                                     
                                                                                                                                                                    
  linearAccel = findLinearAccel(vehicleVelocity, elapsedTime);                                                                                                      
  angularAccel = findAngularAccel(linearAccel, radiusOfWheels);                                                                                                     
  angularVelocity = findAngularVel(angularAccel, elapsedTime);                                                                                                      
  distTraveled = findDistTraveled(radiusOfWheels, angularVelocity);                                                                                                 
  revolutions = findRevolutions(angularAccel, elapsedTime);                                                                                                         
                                                                                                                                                                    
  printResults(linearAccel, angularAccel, angularVelocity, distTraveled, revolutions);                                                                              
  return 0;                                                                                                                                                         
}                                                                                                                                                                  
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: askVelocity                                                                                                                                    
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line): NONE                                                                                                
*                                                                                                                                                                   
*  Function Description: This function asks the user to input the velocity of the vehicle and returns the read value.                                               
*                                                                                                                                                                   
***************************************************************************/                                                                                        
                                                                                                                                                                    
double askVelocity()                                                                                                                                                
{                                                                                                                                                                   
  // LOCAL DECLARATIONS                                                                                                                                             
  double velocity; // VALUE OF THE VELOCITY INPUTTED BY THE USER THAT GETS RETURNED                                                                                 
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  printf("Enter the velocity of the vehicle [m/s] -> ");                                                                                                            
  scanf("%lf", &velocity);                                                                                                                                          
  return velocity;                                                                                                                                                  
} 
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: askTime                                                                                                                                        
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line): NONE                                                                                                
*                                                                                                                                                                   
*  Function Description: This function asks the user to input the time elapsed to reach the velocity of the vehicle and returns the read value.                     
*                                                                                                                                                                   
***************************************************************************/                                                                                        
                                                                                                                                                                    
double askTime()                                                                                                                                                    
{                                                                                                                                                                   
  // LOCAL DECLARATIONS                                                                                                                                             
  double time; // VALUE OF THE ELAPSED TIME INPUTTED BY THE USER THAT GETS RETURNED                                                                                 
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  printf("Enter elapsed time [s] -> ");                                                                                                                             
  scanf("%lf", &time);                                                                                                                                              
  return time;                                                                                                                                                      
}                                                                                                                                                                   
                                                                                                                                                                    
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: askRadius                                                                                                                                      
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line): NONE                                                                                                
*                                                                                                                                                                   
*  Function Description: This function asks the user to input the radius of the wheels and returns the read value.                                                  
*                                                                                                                                                                   
***************************************************************************/                                                                                                                                                                 
double askRadius()                                                                                                                                                  
{                                                                                                                                                                   
  // LOCAL DECLARATIONS                                                                                                                                             
  double radius; // VALUE OF THE RADIUS OF THE WHEELS INPUTTED BY THE USER THAT GETS RETURNED                                                                       
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  printf("Enter radius of wheels [m] -> ");                                                                                                                         
  scanf("%lf", &radius);                                                                                                                                            
  return radius;                                                                                                                                                    
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
*    1. double linearAccel - Calculated linear acceleration of the vehicle from the inputted givens                                                                 
*    2. double angularAccel - Calculated angular acceleration of the vehicle from the inputted givens                                                               
*    3. double angularVelocity - Calculated final angular velocity of the vehicle from the inputted givens                                                          
*    4. double distTraveled - Calculated distance traveled by the vehicle during the elapsed time                                                                   
*    5. double revolutions - Calculated number of revolutions the wheels of the vehicle make in the elapsed time.                                                   
*                                                                                                                                                                   
*  Function Description: This function prints the results of the calculations by getting passed the numbers and printing them out.                                  
*                                                                                                                                                                   
***************************************************************************/                                                                                        
                                                                                                                                                                    
void printResults(double linearAccel, double angularAccel, double angularVelocity, double distTraveled, double revolutions)                                         
{                                                                                                                                                                   
  // EXECUTABLE STATEMENTS                                                                                                                                          
  printf("\nLinear Acceleration: %.2lf [m/s^2]", linearAccel);                                                                                                      
  printf("\nAngular Acceleration: %.2lf [rad/s^2]", angularAccel);                                                                                                  
  printf("\nFinal Angular Velocity: %.2lf [rad/s]", angularVelocity);                                                                                               
  printf("\nDistance Traveled: %.2lf [m]", distTraveled);                                                                                                           
  printf("\nNumber of Revolutions: %.2lf\n", revolutions);                                                                                                          
}   
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: findLinearAccel                                                                                                                                
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line):                                                                                                     
*    1. double velocity - The final velocity of the vehicle given by the user                                                                                       
*    2. double time - The time it takes to reach the user's final velocity                                                                                          
*                                                                                                                                                                   
*  Function Description: This function gets passed the vehicle's velocity and the elapsed time to calculated the linear acceleration by dividing the velocity by the
 time.                                                                                                                                                              
*                                                                                                                                                                   
***************************************************************************/                                                                                        
                                                                                                                                                                    
double findLinearAccel(double velocity, double time)                                                                                                                
{                                                                                                                                                                   
  // EXECUTABLE STATEMENTS                                                                                                                                          
  return velocity / time;                                                                                                                                           
}                                                                                                                                                                   
                                                                                                                                                                    
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: findAngularAccel                                                                                                                               
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line):                                                                                                     
*    1. double linearAccel - The previously calculated linear acceleration                                                                                          
*    2. double radius - The radius of the wheels that the user entered                                                                                              
*                                                                                                                                                                   
*  Function Description: This function gets passed the linear acceleration calculated by the previous function and the radius of the wheels that the user entered, a
nd it divides the linear acceleration by the wheel's radius and returns that to give the angular acceleration.                                                      
*                                                                                                                                                                   
***************************************************************************/                                                                                        
                                                                                                                                                                    
double findAngularAccel(double linearAccel, double radius)                                                                                                          
{                                                                                                                                                                   
  // EXECUTABLE STATEMENTS                                                                                                                                          
  return linearAccel / radius;                                                                                                                                      
}
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: findAngularVel                                                                                                                                 
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line):                                                                                                     
*    1. double angularAccel - The previously calculated angular acceleration                                                                                        
*    2. double time - The time it takes to reach the user's final velocity                                                                                          
*                                                                                                                                                                   
*  Function Description: This function gets passed the angular acceleration calculated in the findAngularAccel() function and the user-entered elapsed time to calcu
lated the final angular velocity by returning the product of the two parameters.                                                                                    
*                                                                                                                                                                   
***************************************************************************/                                                                                        
                                                                                                                                                                    
double findAngularVel(double angularAccel, double time)                                                                                                             
{                                                                                                                                                                   
  // EXECUTABLE STATEMENTS                                                                                                                                          
  return angularAccel * time;                                                                                                                                       
}                                                                                                                                                                   
                                                                                                                                                                    
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: findDistTraveled                                                                                                                               
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line):                                                                                                     
*    1. double radius - The radius of the wheels that the user entered                                                                                              
*    2. double angularVel - The angular velocity calculated by the findAngularVel() function                                                                        
*                                                                                                                                                                   
*  Function Description: This function gets passed the angular velocity calculated by the findAngularVel() function and the user-entered radius of the wheels. It re
turns the product of these two parameters to give the distance traveled by the vehicle.                                                                             
*                                                                                                                                                                   
***************************************************************************/                                                                                                                                                                       
double findDistTraveled(double radius, double angularVel)                                                                                                           
{                                                                                                                                                                   
  // EXECUTABLE STATEMENTS                                                                                                                                          
  return radius * angularVel;                                                                                                                                       
}                                                                                                                                                                   
                                                                                                                                                                    
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: findRevolutions                                                                                                                                
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line):                                                                                                     
*    1. double angularAccel - The angular acceleration calculated by findAngularAccel()                                                                             
*    2. double time - The time it takes to reach the user-entered final velocity                                                                                    
*                                                                                                                                                                   
*  Function Description: This function gets passed the angular acceleration calculated by the findAngularAccel() function and the user-entered time elapsed to reach
 the final velocity. It then squares the time and multiplies it by 0.5, the angular acceleration, and 1/(2pi) and returns this number to give the number of revoluti
ons the wheels make over the time period.                                                                                                                           
*                                                                                                                                                                   
***************************************************************************/                                                                                        
                                                                                                                                                                    
double findRevolutions(double angularAccel, double time)                                                                                                            
{                                                                                                                                                                   
  // EXECUTABLE STATEMENTS                                                                                                                                          
  return 0.5 * angularAccel * pow(time, 2) * (1 / (2 * M_PI));                                                                                                      
