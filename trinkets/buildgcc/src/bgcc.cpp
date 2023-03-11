/* Includes */
#include <stdio.h> /* Standard input/output library */
#include <curses.h> /* For user-friendly mode */

/* Function declarations for functions below main */
void check_args(short int *wtd); /* wtd = What To Do code */

/* Data and variable stuff */
union u_wtd {     /* This union contains variables that are to be used in     */
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

struct s_args {
  int argc;
  char argv[];
} args;

/* main: get the program started and figure out what to do */
int main(int argc, char *argv[]) {
  int i;

  args.argc = argc;
  for (i = 0; i < argc; i++) {
    args.argv[i] = *argv[i];
  }

  printf("ee2\n\n");

  /* check_args(wtd_c.p_args); */
  /* for (i = 0; i < argc; i++) {
    printf("\narg%d=%s", i, argv[i]);
  } */

  /* printf("\n\n%d %s\n\n", argc, argv[1]); */

  /* This will run if arguments are not recognized */
  /* printf("\nUnknown argument(s) '-h'. Please fix it and try again."); */
  return 0;
}

/* check_args: check arguments passed to the program */
/* void check_args(short int *wtd) {
  int i;
  printf("ee\n\n");
  for (i = 0; i < args.argc; i++) {
    printf("\narg%d=%s", i, args.argv[i]);
  }
} */


/* Annex A: What-To-Do Code Reference
1. Print help information about the program
2. Print version information
*/