// Includes 
#include <iostream> // Standard input/output library 
#include <curses.h> // For user-friendly mode 

// Function declarations for functions below main 

// Data and variable stuff 

// main: get the program started and figure out what to do 
int main(int argc, char *argv[]) {
  std::cout << "It ran!" << std::endl << std::endl;

  // This will run if arguments are not recognized 
  std::cout << std::endl << "Unknown argument(s) '" << "-h" << "'. Please fix it and try again."; 
  return 0;
}