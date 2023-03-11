//Definitions
#define P_BV_DEV //Program build version = development
#define P_BV_PROD //Program build version = production

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
    boost::program_options::options_description options_description("[DEVELOPMENT VERSION] buildgcc v0.0.1.0 Help", 100);
    options_description.add_options()
      ("help", "Print help message (the thing that you're reading right now)")
      ("errorhelp", "Print basic information about all error codes")
      ("errorcode", boost::program_options::value(&errorcode), "Displays a longer description for a specific error code with possible solutions. Replace 'arg' with your error code\n") //`\n` to add a separator
      ("renderer-cpu", "Use the CPU renderer");

    boost::program_options::variables_map p_variables_map;
    boost::program_options::store(boost::program_options::parse_command_line(pargc, pargv, options_description), p_variables_map);
    boost::program_options::notify(p_variables_map);

    if (p_variables_map.count("help")) {
      std::cout << options_description << std::endl;
      quit(0);
    }

    if (p_variables_map.count("errorhelp")) {
      std::cout << "There are different types of errors in Blender++. And it is generally good computer programming practice to assign an ID or code to every error. The types of errors in Blender++ are listed below. Run the application with \"--errorhelp {your error code here}\" to learn about possible solutions for your error." << std::endl;
      std::cout << "0: Success. Nothing to worry about." << std::endl;
      std::cout << "1: Failed to create GLFW window." << std::endl;
      std::cout << "2: Failed to initialize GLAD." << std::endl;
      std::cout << "3: Couldn't recognise an argument." << std::endl;
      std::cout << "4: Exception. This should never occur if you are not developing this application." << std::endl;
      std::cout << std::endl << "If you get any other kind of error, please try reinstalling Blender++. If none of these options work, you can reach out to me at HackerDaGreat57@gmail.com." << std::endl << std::endl;
      quit(0);
    }

    if (p_variables_map.count("errorcode")) {
      switch (errorcode) {
        case -1:
          std::cout << "Error -1: Invalid arguments. This means that one of the application's command-line settings (the things that are seperated by spaces and begin with one or two minus symbols) are incorrect and probably have a spelling error. Check your arguments carefully and make sure that not a single letter is off. Remember, the command-line doesn't have autocorrect!" << std::endl;
          quit(0);
        case 0:
          std::cout << "Error 0: Success. \"Error 0\" in any program always means success." << std::endl;
          quit(0);
        case 1:
          std::cout << "Error 1: This means that you tried to run buildgcc in an environment where the necessary dependencies were not installed properly. You specified that that program can attempt to automatically install such dependencies, but it failed. Please install these dependencies manually and try again. See ~/.gccbuild/log.txt for more information." << std::endl;
          quit(0);
        case 2:
          std::cout << "Error 2: This means that you tried to run buildgcc in an environment where the necessary dependencies were not installed properly. You specified that the program should not try to automatically install such dependencies, so it had nothing else to do and quit. Please install these dependencies manually and try again. See ~/.gccbuild/log.txt for more information." << std::endl;
          quit(0);

        default:
          std::cout << "Invalid error code. Try again with the right number this time." << std::endl;
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
  switch(retval) {
    case 0:
      std::cout << "It's done. RAAAAAAR DINOSARU IT WORKS PARRRTy" << std::endl << std::endl;
      break;
  }

  exit(retval);
}