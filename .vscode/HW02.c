#include<stdio.h>                                                                                                                                                   
#include<math.h>                                                                                                                                                    
                                                                                                                                                                    
#define PI 3.1415926 // PI IS A CONSTANT THAT IS USED MULTIPLE TIMES IN THE PROGRAM                                                                                 
                                                                                                                                                                    
int main()                                                                                                                                                          
{                                                                                                                                                                   
                                                                                                                                                                    
  // LOCAL DECLARATIONS                                                                                                                                             
  double vectorADist; // THE DISTANCE ENTERED BY THE USER OF VECTOR A                                                                                               
  double vectorAAngle; // THE ANGLE ENTERED BY THE USER OF VECTOR A                                                                                                 
  double vectorBDist; // THE DISTANCE ENTERED BY THE USER OF VECTOR B                                                                                               
  double vectorBAngle; // THE ANGLE ENTERED BY TE USER OF VECTOR B                                                                                                  
  double resultX; // THE X COMPONENT OF THE RESULTANT VECTOR OF A AND B                                                                                             
  double resultY; // THE Y COMPONENT OF THE RESULTANT VECTOR OF A AND B                                                                                             
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  printf("Enter distance and angle for vector A -> ");                                                                                                              
  scanf("%lf %lf", &vectorADist, &vectorAAngle);                                                                                                                    
                                                                                                                                                                    
  printf("Enter distance and angle for vector B -> ");                                                                                                              
  scanf("%lf %lf", &vectorBDist, &vectorBAngle);                                                                                                                    
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");                                                                                                                
                                                                                                                                                                    
  // FINDING X AND Y COMPONENTS USING COSINE AND SINE FUNCTIONS. CONVERTING ANGLES INTO RADIANS                                                                     
  resultX = vectorADist * cos(vectorAAngle * PI / 180) + vectorBDist * cos(vectorBAngle * PI / 180);                                                                
  resultY = vectorADist * sin(vectorAAngle * PI / 180) + vectorBDist * sin(vectorBAngle * PI / 180);                                                                
                                                                                                                                                                    
  printf("\nResultant x-component: %7.2lf meters", resultX);                                                                                                        
  printf("\nResultant y-component: %7.2lf meters", resultY);                                                                                                        
  printf("\nResultant magnitude: %-9.2lf meters", sqrt(pow(resultX, 2) + pow(resultY, 2))); // USING POW TO SQUARE THE X AND Y COMPONENTS AND SQRT TO COMPLETE PYTHA
GOREAN THEOREM                                                                                                                                                      
  printf("\nResultant direction: %-8.2lf degrees", atan(resultY / resultX) * 180 / PI); // USING ATAN TO FIND ANGLE IN RADIANS AND CONVERTING TO DEGREES            
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");                                                                                                              
                                                                                                                                                                    
  return 0;                                                                                                                                                         
