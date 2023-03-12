//Definitions
#define P_DEV //If this is enabled, then it is definitely a development build

//Includes 
#include <iostream> //Standard input/output library 
#include <curses.h> //For user-friendly mode 

#include <boost/program_options.hpp> //For argument parsing

//Function declarations for functions below main 
void check_params(int pargc, char **pargv);
void quit(short int retval);

//Data and variable stuff (nothing yet)

int main(int argc, char *argv[]) { //main: get the program started and figure out what to do 
  check_params(argc, argv); //Check arguments/parameters/options passed to the program

  return 0; //This will never actually run, it's just there for standards compliance 
}

void check_params(int pargc, char **pargv) { //check_params: check arguments/parameters/options passed to the program
  short int errorcode;

  try {
    boost::program_options::options_description opt_general("General options", 100);
    opt_general.add_options()
      ("help", "Print help message (the thing that you're reading right now)")
      ("errorhelp", "Print basic information about all error codes")
      ("errorcode", boost::program_options::value(&errorcode), "Displays a longer description for a specific error code with possible solutions. Replace 'arg' with your error code\n"); //`\n` to add a separator
    
    boost::program_options::options_description opt_automation("Automation options", 100);
    opt_automation.add_options()
      ("aaf", "Print help message (the thing that you're reading right now)")
      ("eeuh", "Print basic information about all error codes")
      ("yeeos", boost::program_options::value(&errorcode), "Displays a longer description for a specific error code with possible solutions. Replace 'arg' with your error code\n"); //`\n` to add a separator

    #ifdef P_DEV
    boost::program_options::options_description opt_visible("[DEVELOPMENT BUILD] All options for buildgcc vW.X.Y.Z", 100);
    #else
    boost::program_options::options_description opt_visible("All options for buildgcc v1.0.0.0", 100);
    #endif
    opt_visible.add(opt_general).add(opt_automation);

    boost::program_options::options_description opt_all("All allowed options", 100);
    opt_all.add(opt_general).add(opt_automation);

    boost::program_options::variables_map p_variables_map;
    boost::program_options::store(boost::program_options::parse_command_line(pargc, pargv, opt_all), p_variables_map);
    boost::program_options::notify(p_variables_map);

    if (p_variables_map.count("help")) {
      std::cout << opt_visible << std::endl;
      quit(0);
    }

    if (p_variables_map.count("errorhelp")) {
      std::cout << "There are different types of errors in Blender++. And it is generally good computer programming practice to assign an ID or code to every error. The types of errors in Blender++ are listed below. Run the application with \"--errorhelp {your error code here}\" to learn about possible solutions for your error." << std::endl;
      std::cout << "-1: Invalid arguments. You told the program to do something, but it didn't understand what to do." << std::endl;
      std::cout << "0: Success. Nothing to worry about." << std::endl;
      std::cout << "1: Dependencies were not installed. The program tried to install them itself but failed." << std::endl;
      std::cout << "2: Dependencies were not installed, and the program was not allowed to try to install them itself." << std::endl;
      std::cout << std::endl << "If you get any other kind of error, please try reinstalling buildgcc. If nothing solves your problem, you can reach out to me at HackerDaGreat57@gmail.com." << std::endl << std::endl;
      quit(0);
    }

    if (p_variables_map.count("errorcode")) {
      switch (errorcode) {
        case -1:
          std::cout << "Error -1: Invalid arguments. This means that one of the application's command-line settings (the things that are seperated by spaces and begin with one or two minus symbols) are incorrect and probably have a spelling error. Check your arguments carefully and make sure that not a single letter is off. Remember, the command-line doesn't have autocorrect!" << std::endl;
          quit(0);
          break;
        case 0:
          std::cout << "Error 0: Success. \"Error 0\" in any program always means success." << std::endl;
          quit(0);
          break;
        case 1:
          std::cout << "Error 1: This means that you tried to run buildgcc in an environment where the necessary dependencies were not installed properly. You specified that that program can attempt to automatically install such dependencies, but it failed. Please install these dependencies manually and try again. See ~/.gccbuild/log.txt for more information." << std::endl;
          quit(0);
          break;
        case 2:
          std::cout << "Error 2: This means that you tried to run buildgcc in an environment where the necessary dependencies were not installed properly. You specified that the program should not try to automatically install such dependencies, so it had nothing else to do and quit. Please install these dependencies manually and try again. See ~/.gccbuild/log.txt for more information." << std::endl;
          quit(0);
          break;

        default:
          std::cout << "Invalid error code. Try again with the right number. Error codes for this program range from -1 through 2, including 0." << std::endl;
          quit(0);
      }
    }
  }

  catch(std::exception &exception_check_params) {
    std::cout << "Exception while parsing arguments: " << exception_check_params.what() << std::endl;
    quit(-1);
  }
}

void quit(short int retval) {
  /*switch(retval) {
    case 0:
      std::cout << "buildgcc exited with code 0. Everything successful." << std::endl << std::endl;
      break;
  }*/

  exit(retval);
}