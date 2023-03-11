// Includes 
#include <iostream> // Standard input/output library 
#include <curses.h> // For user-friendly mode 
#include <boost/program_options.hpp> // For argument parsing

// Function declarations for functions below main 
void check_params(int pargc, char **pargv);
void quit(short int retval);

// Data and variable stuff 

// main: get the program started and figure out what to do 
int main(int argc, char *argv[]) {
  check_params(argc, argv);

  // This will run if arguments are not recognized 
  std::cout << std::endl << "Unknown argument(s) '" << "-h" << "'. Please fix it and try again." << std::endl << std::endl; 
  return 0;
}

void check_params(int pargc, char **pargv) {
  short int errorcode;

  try {
    boost::program_options::options_description options_description("buildgcc v0.0.0.126 Help", 100);
    options_description.add_options()
      ("help", "Print help message (the thing that you're reading right now)")
      ("errorhelp", "Print basic information about all error codes")
      ("errorcode", boost::program_options::value(&errorcode) , "Displays a longer description for a specific error code with possible solutions. Replace 'arg' with your error code\n") //`\n` to add a separator
      ("renderer-cpu", "Use the CPU renderer");

    boost::program_options::variables_map variables_map;
    boost::program_options::store(boost::program_options::parse_command_line(pargc, pargv, options_description), variables_map);
    boost::program_options::notify(variables_map);

    if (variables_map.count("help")) {
      std::cout << options_description << std::endl;
      quit(0);
    }

    if (variables_map.count("errorhelp")) {
      std::cout << "There are different types of errors in Blender++. And it is generally good computer programming practice to assign an ID or code to every error. The types of errors in Blender++ are listed below. Run the application with \"--errorhelp {your error code here}\" to learn about possible solutions for your error." << std::endl;
      std::cout << "0: Success. Nothing to worry about." << std::endl;
      std::cout << "1: Failed to create GLFW window." << std::endl;
      std::cout << "2: Failed to initialize GLAD." << std::endl;
      std::cout << "3: Couldn't recognise an argument." << std::endl;
      std::cout << "4: Exception. This should never occur if you are not developing this application." << std::endl;
      std::cout << std::endl << "If you get any other kind of error, please try reinstalling Blender++. If none of these options work, you can reach out to me at HackerDaGreat57@gmail.com." << std::endl << std::endl;
      quit(0);
    }

    if (variables_map.count("errorcode")) {
      switch (errorcode) {
        case 0:
          std::cout << "Error 0: Success. Error 0 in any program always means success." << std::endl;
          quit(0);
        case 1:
          std::cout << "Error 1: Failed to create GLFW window. This means that your graphics card (aka GPU) doesn't support OpenGL 4.6. Try rerunning Blender++ with --renderer-cpu." << std::endl;
          quit(0);
        case 2:
          std::cout << "Error 2: Failed to initialize GLAD. This means that your computer either does not have a graphics card (aka GPU) or is too old. Try running the application with --renderer-cpu." << std::endl;
          quit(0);
        case 3:
          std::cout << "Error 3: Invalid arguments. This means that one of the application's command-line settings (the things that are seperated by spaces and begin with --) are incorrect and probably have a spelling error. Check your arguments carefully and make sure that not a single letter is off. Remember, the command-line doesn't have autocorrect!" << std::endl;
          quit(0);
        case 4:
          std::cout << "Error 4: Exception. This should never occur if you are not developing this application, however you can file a bug report at https://github.com/hackerdagreat57/bpp/issues if you are an end-user." << std::endl;
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