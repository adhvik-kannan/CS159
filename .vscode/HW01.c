#include<stdio.h>                                                                                                                                                   
                                                                                                                                                                    
int main(void)                                                                                                                                                      
{                                                                                                                                                                   
  // LOCAL DECLARATIONS                                                                                                                                             
  float temperature; // CONTAINS THE VALUE OF THE TEMPERATURE GIVEN BY THE USER THAT IS CONVERTED INTO THE EQUIVALENT VALUE OF OTHER TEMPERATURE SCALES             
                                                                                                                                                                    
  // EXECUTABLE STATEMENTS                                                                                                                                          
                                                                                                                                                                    
  // ASKING FOR USER INPUT                                                                                                                                          
  printf("\nEnter the temperature in Kelvin -> ");                                                                                                                  
  scanf("%f", &temperature);                                                                                                                                        
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");                                                                                                              
                                                                                                                                                                    
  // CONVERTING FROM KELVIN TO CELSIUS                                                                                                                              
  temperature = temperature - 273.15;                                                                                                                               
  printf("\nTemperature in Celsius: %.1f", temperature);                                                                                                            
                                                                                                                                                                    
  // CONVERTING FROM CELSIUS TO FAHRENHEIT                                                                                                                          
  temperature = (temperature * 9) / 5 + 32;                                                                                                                         
  printf("\nTemperature in Fahrenheit: %.1f", temperature);                                                                                                         
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");                                                                                                            
                                                                                                                                                                    
  // CONVERTING FROM FAHRENHEIT TO RANKINE                                                                                                                          
  temperature = temperature + 459.67;                                                                                                                               
  printf("\nTemperature in Rankine: %.1f", temperature);                                                                                                            
                                                                                                                                                                    
  // CONVERTING FROM RANKINE TO DELISLE                                                                                                                             
  temperature = (671.67 - temperature) * 5 / 6;                                                                                                                     
  printf("\nTemperature in Delisle: %.1f", temperature);                                                                                                            
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");                                                                                                          
                                                                                                                                                                    
  return 0;                                                                                                                                                         
}                                                                                                                                                                   
