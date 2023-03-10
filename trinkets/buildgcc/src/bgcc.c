/* Includes */
#include <stdio.h> /* Standard input/output library */
#include <curses.h> /* For user-friendly mode */

/* Function declarations for functions below main */
void check_args(short int *wtd); /* wtd = What To Do code */

/* Data and variable stuff */
short int m_wtd; /* m is there to differentiate between check_args()'s        */
                 /* pointer and the actual variable ('m' is chosen randomly)  */

union wtd {       /* This union contains variables that are to be used in     */
  short int args; /* cases that tell the program figure out what to do. Each  */
  short int ret;  /* What-To-Do Code indicates a specific thing. A list is    */
};                /* in Annex A, at the bottom of the source code file.       */

/* main: get the program started and figure out what to do */
int main(int argc, char *argv[]) {
  check_args(&m_wtd); /* Check arguments */
  
  printf("Arguments passed: %d, %s\n", argc, argv[0]);

  int i;
  for (i=0; i< argc; i++) {
     printf("\narg%d=%s", i, argv[i]);
  }

  return 0;
}

/* check_args: check arguments passed to the program */
void check_args(short int *wtd) {
  /* *wtd = 5; */
}


/* Annex A: What-To-Do Code Reference
1. Print help information about the program

*/