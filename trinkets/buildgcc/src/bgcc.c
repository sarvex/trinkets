/* Includes */
#include <stdio.h> /* Standard input/output library */
#include <curses.h> /* For user-friendly mode */

/* Function declarations for functions below main */
void check_args(short int *wtd); /* WTD = What To Do code */

/* main: get the program started and figure out what to do */
int main(int argc, char *argv[]) {
  short int m_wtd;
  check_args(&m_wtd); /* Check arguments */
  printf("Arguments: %d", m_wtd);

  return 0;
}

/* check_args: check arguments passed to the program */
void check_args(short int *wtd) {
  *wtd = 5;
}