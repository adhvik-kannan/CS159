#include<stdio.h>

int main()                                                                                                                                                          
{                                                                                                                                                                   
  //Local Declarations                                                                                                                                              
  char lc; //Lower-case Character                                                                                                                                   
  char uc;  //Upper-case Character                                                                                                                                  
  int ascii; //ASCII Integer                                                                                                                                        
  int lcAscii; //ASCII Lowercase                                                                                                                                    
  int ucAscii; //ASCII Uppercase                                                                                                                                    
  char asciiChar; //ASCII Character                                                                                                                                 
  int lcPosition; //ASCII Lowercase Position                                                                                                                        
  int ucPosition; //ASCII Uppercase Position                                                                                                                        
  int aboveAsciiPosition; //Character above the ASCII Character                                                                                                     
  int belowAsciiPosition; //Character below the ASCII Character                                                                                                     
                                                                                                                                                                    
  //Executable Statements                                                                                                                                           
  printf("Enter a lowercase character [a-z] -> ");                                                                                                                  
  scanf("%c", &lc);                                                                                                                                                 
                                                                                                                                                                    
  printf("Enter an uppercase character [A-Z] -> ");                                                                                                                 
  scanf("\n%c", &uc);                                                                                                                                               
                                                                                                                                                                    
  printf("Enter an ASCII integer value -> ");                                                                                                                       
  scanf("\n%d", &ascii);                                                                                                                                            
                                                                                                                                                                    
  lcAscii = lc; // Converting lowercase letter to equivalent ASCII number                                                                                           
  ucAscii = uc; // Converting uppercase letter to equivalent ASCII number                                                                                           
  asciiChar = ascii; // Converting ASCII number to equivalent symbol/letter                                                                                         
  lcPosition = lcAscii - 96; // Finding the position of the lowercase letter in the alphabet                                                                        
  ucPosition = ucAscii - 64; // Finding the position of the uppercase letter in the alphabet                                                                        
  aboveAsciiPosition = ascii - 1; // Finding the position of the adjacent ASCII number above the entered ASCII number                                               
  belowAsciiPosition = ascii + 1; // Finding the position of the adjacent ASCII number below the entered ASCII number                                               
                                                                                                                                                                    
  printf("\nThe ASCII value of %c is: %d", lc, lcAscii);                                                                                                            
  printf("\nThe ASCII value of %c is: %d", uc, ucAscii);                                                                                                            
  printf("\nThe character of ASCII %d is: %c\n", ascii, asciiChar);                                                                                                 
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");                                                                                                            
                                                                                                                                                                    
  printf("Lowercase position in the alphabet: %5d", lcPosition);                                                                                                    
  printf("\nUppercase position in the alphabet: %5d\n", ucPosition);                                                                                                
                                                                                                                                                                    
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");                                                                                                            
  printf("The characters adjacent to ASCII %d: %c %c \n", ascii, aboveAsciiPosition, belowAsciiPosition);                                                           
                                                                                                                                                                    
  return 0;                                                                                                                                                         
