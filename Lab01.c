#include<stdio.h>                                                                                                                                                   
                                                                                                                                                                    
int main(void)                                                                                                                                                      
{                                                                                                                                                                   
                                                                                                                                                                    
  // LOCAL DECLARATIONS                                                                                                                                             
  float feet; // measurement in feet                                                                                                                                
  float miles; //measurement in miles                                                                                                                               
  float lbs; //measurement in lbs                                                                                                                                   
  float meters; //measurement converted to meters                                                                                                                   
  float kilometers; //measurement converted to kilometers                                                                                                           
  float kilograms; //measurement converted to kilograms                                                                                                             
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
  printf("(1) Enter a value in feet -> ");                                                                                                                          
  scanf("%f", &feet);                                                                                                                                               
                                                                                                                                                                    
  printf("(2) Enter a value in miles -> ");                                                                                                                         
  scanf("%f", &miles);                                                                                                                                              
                                                                                                                                                                    
  printf("(3) Enter a value in lbs -> ");                                                                                                                           
  scanf("%f", &lbs);                                                                                                                                                
                                                                                                                                                                    
  printf("\n-=-=-=-=-=-=-=-=-=-");                                                                                                                                  
                                                                                                                                                                    
  meters = feet * .3048;                                                                                                                                            
  kilometers = miles * 1.60934;                                                                                                                                     
  kilograms = lbs * .453592;                                                                                                                                        
                                                                                                                                                                    
  printf("\n(1) The corresponding value in meters: %.2f", meters);                                                                                                  
  printf("\n(2) The corresponding value in kilometers: %.2f", kilometers);                                                                                          
  printf("\n(3) The corresponding value in kilograms: %.2f\n", kilograms);                                                                                          
                                                                                                                                                                    
  printf("-=-=-=-=-=-=-=-=-=-\n");                                                                                                                                  
                                                                                                                                                                    
  return(0);                                                                                                                                                        
