#include<stdio.h>                                                                                                                                                   
#include<math.h>                                                                                                                                                    
                                                                                                                                                                    
int main()                                                                                                                                                          
{                                                                                                                                                                   
  //declarations                                                                                                                                                    
  int optionNumber; // Holds the option that the user chose                                                                                                         
  float valueInputted; // The height or radius that the user entered                                                                                                
  float valueCalculated; // The height or radius that is calculated based on the option chosen                                                                      
  int decimalPlaces; // How many decimal places that we go to.                                                                                                      
                                                                                                                                                                    
 // EXECUTABLE STATEMENTS                                                                                                                                           
  printf("\nEnter option and value -> ");                                                                                                                           
  scanf("%d %f", &optionNumber, &valueInputted);                                                                                                                    
                                                                                                                                                                    
  valueCalculated =  (optionNumber % 2) * ((2 * valueInputted) / (valueInputted - 2)) + (optionNumber / 2) * ((2 * pow(valueInputted, 2)) / (pow(valueInputted, 2) -
 (2 * valueInputted))); // This code mathematically determines whether to calculate the height or the radius by using modulus to determine if option 1 was chosen an
d division to choose if option 2 was chosen. 1 % 2 would return 1, while 1 / 2 would return 0, making sure that the radius is calculated, and vice versa if optionNu
mber == 2; The height and radius are calculated by setting the volume and surface areas of the cylinder equal to each other and solving for each variable.          
                                                                                                                                                                    
  decimalPlaces = (optionNumber % 2) * 3 + (optionNumber / 2) * 2; // Determining how many decimal places based on the option chosen as the calculated variable has 
3 decimal places.                                                                                                                                                   
  printf("\nRadius: %.*f", decimalPlaces, (optionNumber % 2) * valueCalculated + (optionNumber / 2) * valueInputted);                                               
  decimalPlaces = (optionNumber % 2) * 2 + (optionNumber / 2) * 3;                                                                                                  
  printf("\nHeight: %.*f \n", decimalPlaces, (optionNumber % 2) * valueInputted + (optionNumber / 2) * valueCalculated);                                            
                                                                                                                                                                    
  return(0);                                                                                                                                                        
