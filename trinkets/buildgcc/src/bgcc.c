/* Includes */
#include <stdio.h> /* Standard input/output library */
#include <curses.h> /* For user-friendly mode */

/* Function declarations for functions below main */
void check_args(short int *wtd); /* wtd = What To Do code */

/* Data and variable stuff */
short int m_wtd; /* m is there to differentiate between check_args()'s        */
                 /* pointer and the actual variable ('m' is chosen randomly)  */

union s_wtd {     /* This union contains variables that are to be used in     */
                  /* cases that help the program figure out what to do. Each  */
                  /* What-To-Do Code indicates a specific thing. A reference  */
                  /* list is in Annex A, at the bottom of the source code     */
                  /* file. (A union is used to increase code readability by   */
                  /* using different variable names in different parts of the */
                  /* program, but all use the same What-To-Do Codes.)         */
  short int p_args; /* Program arguments */
  short int f_ret;  /* Function return code (generally used for anything that */
                    /* isn't related to program arguments)                    */
} wtd_c; /* We will acess this as wtc_c */

/* main: get the program started and figure out what to do */
int main(int argc, char *argv[]) {
  check_args(&m_wtd); /* Check arguments */

  return 0;
}

/* check_args: check arguments passed to the program */
void check_args(short int *wtd) {
  wtd_c.p_args = 5;
  printf("%d", wtd_c.p_args);
}


/* Annex A: What-To-Do Code Reference
1. Print help information about the program
2. Print version information
*/