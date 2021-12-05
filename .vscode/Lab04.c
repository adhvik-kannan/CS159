#include<stdio.h>                                                                                                                                                   
#include<math.h>                                                                                                                                                    
                                                                                                                                                                    
// FUNCTION DECLARATIONS                                                                                                                                            
double findAcceleration(double, double, double);                                                                                                                    
void askAngle();                                                                                                                                                    
void askMass();                                                                                                                                                     
void askFriction();                                                                                                                                                 
void scanAngle(double*);                                                                                                                                            
void scanMass(double*);                                                                                                                                             
void scanFriction(double*);                                                                                                                                         
void printAccelWithFriction(double*);                                                                                                                               
void printAccelWithoutFriction(double*);                                                                                                                            
                                                                                                                                                                    
int main()                                                                                                                                                          
{                                                                                                                                                                   
  // LOCAL DECLARATIONS                                                                                                                                             
  double angleOfPlane; // Angle of the slope that the object is accelerating on                                                                                     
  double massOfObject; // Mass of the object that is on the slope                                                                                                   
  double frictionOfSurface; // Friction of the surface that the object is accelerating on                                                                           
  double accelerationWithFriction; // Acceleration calculated from the function with friction                                                                       
  double accelerationWithoutFriction; // Acceleration calculated from the function without friction                                                                 
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  askAngle();                                                                                                                                                       
  scanAngle(&angleOfPlane);                                                                                                                                         
                                                                                                                                                                    
  askMass();                                                                                                                                                        
  scanMass(&massOfObject);                                                                                                                                          
                                                                                                                                                                    
  askFriction();                                                                                                                                                    
  scanFriction(&frictionOfSurface);                                                                                                                                 
                                                                                                                                                                    
  accelerationWithFriction = findAcceleration(massOfObject, angleOfPlane, frictionOfSurface); // FUNCTION CALL WITH FRICTION GIVEN                                  
  accelerationWithoutFriction = findAcceleration(massOfObject, angleOfPlane, 0); // FUNCTION CALL WITH FRICTION EQUALS 0                                            
                                                                                                                                                                    
  printAccelWithFriction(&accelerationWithFriction);                                                                                                                
  printAccelWithoutFriction(&accelerationWithoutFriction);                                                                                                          
                                                                                                                                                                    
  return 0;                                                                                                                                                         
}                            
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: askAngle                                                                                                                                       
*                                                                                                                                                                   
*  Function Return Type: void                                                                                                                                       
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line): NONE                                                                                                
*                                                                                                                                                                   
*  Function Description: Asks the user to enter the angle of the plane that the object is on.                                                                       
*                                                                                                                                                                   
***************************************************************************/                                                                                        
void askAngle()                                                                                                                                                     
{                                                                                                                                                                   
  printf("Enter angle of plane (degrees) -> ");                                                                                                                     
}                                                                                                                                                                   
                                                                                                                                                                    
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: scanAngle                                                                                                                                      
*                                                                                                                                                                   
*  Function Return Type: void                                                                                                                                       
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line):                                                                                                     
*    1. double *angleOfPlane - Points at the address of angleOfPlane to change it directly                                                                          
*                                                                                                                                                                   
*  Function Description: Scans the user's inputted angle and directly places it into the angleOfPlane by using its address to change it for the whole program.      
*                                                                                                                                                                   
***************************************************************************/                                                                                        
void scanAngle(double *angleOfPlane)                                                                                                                                
{                                                                                                                                                                   
  scanf("%lf", angleOfPlane);                                                                                                                                       
}
 /***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: askMass                                                                                                                                        
*                                                                                                                                                                   
*  Function Return Type: void                                                                                                                                       
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line): NONE                                                                                                
*                                                                                                                                                                   
*  Function Description: Asks the user to enter the angle of the plane that the object is on.                                                                       
*                                                                                                                                                                   
***************************************************************************/                                                                                        
void askMass()                                                                                                                                                      
{                                                                                                                                                                   
  printf("Enter mass of the object (kg) -> ");                                                                                                                      
}                                                                                                                                                                   
                                                                                                                                                                    
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: scanMass                                                                                                                                       
*                                                                                                                                                                   
*  Function Return Type: void                                                                                                                                       
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line):                                                                                                     
*    1. double *massOfObject - Points at the address of massOfObject to change it directly                                                                          
*                                                                                                                                                                   
*  Function Description: Scans the user's inputted mass and directly places it into the massOfObject by using its address to change it for the whole program.       
*                                                                                                                                                                   
***************************************************************************/                                                                                        
void scanMass(double *massOfObject)                                                                                                                                 
{                                                                                                                                                                   
  scanf("%lf", massOfObject);                                                                                                                                       
}     
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: askFriction                                                                                                                                    
*                                                                                                                                                                   
*  Function Return Type: void                                                                                                                                       
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line): NONE                                                                                                
*                                                                                                                                                                   
*  Function Description: Asks the user to enter the angle of the plane that the object is on.                                                                       
*                                                                                                                                                                   
***************************************************************************/                                                                                        
void askFriction()                                                                                                                                                  
{                                                                                                                                                                   
  printf("Enter friction of surface (N) -> ");                                                                                                                      
}                                                                                                                                                                   
                                                                                                                                                                    
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: scanFriction                                                                                                                                   
*                                                                                                                                                                   
*  Function Return Type: void                                                                                                                                       
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line):                                                                                                     
*    1. double *frictionOfSurface - Points at the address of frictionOfSurface to change it directly                                                                
*                                                                                                                                                                   
*  Function Description: Scans the user's inputted friction and directly places it into the frictionOfSurface by using its address to change it for the whole progra
m.                                                                                                                                                                  
*                                                                                                                                                                   
***************************************************************************/                                                                                        
void scanFriction(double *frictionOfSurface)                                                                                                                        
{                                                                                                                                                                   
  scanf("%lf", frictionOfSurface);                                                                                                                                  
}         
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: printAccelWithFriction                                                                                                                         
*                                                                                                                                                                   
*  Function Return Type: void                                                                                                                                       
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line):                                                                                                     
*    1. double *accelerationWithFriction - Points at the address of accelerationWithFriction to access it directly and from outside the main method.                
*                                                                                                                                                                   
*  Function Description: This function prints the calculated acceleration with friction by being passed the address of the variable as a parameter and pointing at i
t and using it.                                                                                                                                                     
*                                                                                                                                                                   
***************************************************************************/                                                                                        
void printAccelWithFriction(double *accelerationWithFriction)                                                                                                       
{                                                                                                                                                                   
  printf("\nAcceleration with friction: %.2lf m/s^2", *accelerationWithFriction);                                                                                   
}                                                                                                                                                                   
                                                                                                                                                                    
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: printAccelWithoutFriction                                                                                                                      
*                                                                                                                                                                   
*  Function Return Type: void                                                                                                                                       
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line):                                                                                                     
*    1. double *accelerationWithoutFriction - Points at the address of accelerationWithoutFriction to access it directly and from outside the main method.          
*                                                                                                                                                                   
*  Function Description: This function prints the calculated acceleration without friction by being passed the address of the variable as a parameter and pointing a
t it and using it.                                                                                                                                                  
*                                                                                                                                                                   
***************************************************************************/                                                                                        
void printAccelWithoutFriction(double *accelerationWithoutFriction)                                                                                                 
{                                                                                                                                                                   
  printf("\nAcceleration without friction: %.2lf m/s^2\n", *accelerationWithoutFriction);                                                                           
}   
/***************************************************************************                                                                                        
*                                                                                                                                                                   
*  Function Information                                                                                                                                             
*                                                                                                                                                                   
*  Name of Function: findAcceleration                                                                                                                               
*                                                                                                                                                                   
*  Function Return Type: double                                                                                                                                     
*                                                                                                                                                                   
*  Parameters (list data type, name, and comment one per line):                                                                                                     
*    1. double massOfObject - Mass of the Object for acceleration calculation                                                                                       
*    2. double angleOfPlane - Angle of the plane the object is on for acceleration calculation                                                                      
*    3. double frictionOfSurface - Friction of the surface that the object is on for acceleration calculation                                                       
*                                                                                                                                                                   
*  Function Description: Returns the result of the force of gravity in the x-direction subtracted from the friction of the surface and divides that by the mass to f
ind the acceleration.                                                                                                                                               
*                                                                                                                                                                   
***************************************************************************/                                                                                        
double findAcceleration(double massOfObject, double angleOfPlane, double frictionOfSurface)                                                                         
{                                                                                                                                                                   
  // LOCAL DECLARATIONS                                                                                                                                             
  double mass; // MASS OF USER'S INPUTTED MASS                                                                                                                      
  double angle; // ANGLE OF THE USER'S INPUTTED ANGLE                                                                                                               
  double friction; // FRICTION OF THE USER'S INPUTTED FRICTION                                                                                                      
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  mass = massOfObject;                                                                                                                                              
  angle = angleOfPlane;                                                                                                                                             
  friction = frictionOfSurface;                                                                                                                                     
                                                                                                                                                                    
  return (mass * 9.8 * sin(angle * M_PI / 180) - friction) / mass;                                                                                                  
