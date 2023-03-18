//Definitions
#define P_DEV //If this is enabled, then it is definitely a development build

//Includes 
#include <iostream> //Standard input/output library 
#include <curses.h> //For user-friendly mode 

#include <boost/program_options.hpp> //For argument parsing

//Function declarations for functions below main 
void check_params(int pargc, char **pargv);

//Data and variable stuff (nothing yet)

int main(int argc, char *argv[]) { //main: get the program started and figure out what to do 
  check_params(argc, argv); //Check arguments/parameters/options passed to the program

  return 0; //This will never actually run, it's just there for standards compliance 
}

/*pair<string, string> reg_foo(const string& s) //Custom argument parsing (from https://github.com/boostorg/program_options/blob/develop/example/custom_syntax.cpp)
{
    if (s.find("-") == 0) {
        if (s.substr(2, 3) == "no-")
            return make_pair(s.substr(5), string("false"));
        else
            return make_pair(s.substr(2), string("true"));
    } else {
        return make_pair(string(), string());
    }
}*/

std::pair<std::string, std::string> custom_argparse(const std::string& s) //Custom argument parsing (modified version of https://github.com/boostorg/program_options/blob/develop/example/custom_syntax.cpp)
{
    if (s.find("-f") == 0) {
        if (s.substr(2, 3) == "ec")
            return std::make_pair(s.substr(5), std::string("false"));
        else
            return std::make_pair(s.substr(2), std::string("true"));
    } else {
        return std::make_pair(std::string(), std::string());
    }    
}

void check_params(int pargc, char **pargv) { //check_params: check arguments/parameters/options passed to the program
  short int errorcode; //Taken as argument for --errorcode

  try {
    boost::program_options::options_description opt_general("General options", 100); //Create general options set
    opt_general.add_options() //Add options to the general set...
      ("help,h", "Print help message (the thing that you're reading right now)")
      ("errorhelp", "Print basic information about all error codes")
      ("errorcode", boost::program_options::value(&errorcode), "Displays a longer description for a specific error code with possible solutions. Replace 'arg' with your error code");
    
    boost::program_options::options_description opt_automation("Automation options", 100); //Create automation options set
    opt_automation.add_options() //Add options to the automation set...
      ("outdir", "The directory where your build will be saved")
      ("srcdir", "The directory where GCC source code is located. This program comes with GCC 12.2 sources included, but you can compile it from other sources if you'd like.")
      ("objdir", "The directory where object files will be placed.");

    #ifdef P_DEV
    boost::program_options::options_description opt_visible("[DEVELOPMENT BUILD] All options for buildgcc vW.X.Y.Z", 100); /*****************************************/
    #else                                                                                                                  /* Print the header of the help menu and */
    boost::program_options::options_description opt_visible("All options for buildgcc v1.0.0.0", 100);                     /* point out if it's a development build */
    #endif                                                                                                                 /*****************************************/
    opt_visible.add(opt_general).add(opt_automation); //The user will see this.

    boost::program_options::options_description opt_all("All allowed options", 100); //Every single option that exists
    opt_all.add(opt_general).add(opt_automation);
    /*using namespace std;
    using namespace boost::program_options;*/
    boost::program_options::variables_map p_variables_map;
    boost::program_options::store(boost::program_options::parse_command_line(pargc, pargv, opt_all), p_variables_map); //The program needs to know about ALL arguments but the user usually needs only the default visible ones
    boost::program_options::notify(p_variables_map); //Set it up and get ready for parsing
    boost::program_options::store(boost::program_options::command_line_parser(pargc, pargv).options(opt_all).extra_parser(custom_argparse).run(), p_variables_map);

    if (p_variables_map.count("help")) { //--help
      std::cout << opt_visible << std::endl << std::endl << "Remember, you can run 'bgcc --auto' to get fully automated compilation into default directories like /bin, etc. Refer to the official GCC configuration options reference for more details." << std::endl << std::endl;
      exit(0);
    }

    if (p_variables_map.count("errorhelp")) { //--errorhelp
      std::cout << "There are different types of errors in Blender++. And it is generally good computer programming practice to assign an ID or code to every error. The types of errors in Blender++ are listed below. Run the application with \"--errorhelp {your error code here}\" to learn about possible solutions for your error." << std::endl;
      std::cout << "-1: Invalid arguments. You told the program to do something, but it didn't understand what to do." << std::endl;
      std::cout << "0: Success. Nothing to worry about." << std::endl;
      std::cout << "1: Dependencies were not installed. The program tried to install them itself but failed." << std::endl;
      std::cout << "2: Dependencies were not installed, and the program was not allowed to try to install them itself." << std::endl;
      std::cout << std::endl << "If you get any other kind of error, please try reinstalling buildgcc. If nothing solves your problem, you can report an issue at https://github.com/HackerDaGreat57/trinkets/issues." << std::endl << std::endl;
      exit(0);
    }

    if (p_variables_map.count("errorcode")) { //--errorcode <number>
      switch (errorcode) {
        case -1:
          std::cout << "Error -1: Invalid arguments. This means that one of the application's command-line settings (the things that are seperated by spaces and begin with one or two minus symbols) are incorrect and probably have a spelling error. Check your arguments carefully and make sure that not a single letter is off. Remember, the command-line doesn't have autocorrect!" << std::endl;
          exit(0);
          break;
        case 0:
          std::cout << "Error 0: Success. \"Error 0\" in any program always means success." << std::endl;
          exit(0);
          break;
        case 1:
          std::cout << "Error 1: This means that you tried to run buildgcc in an environment where the necessary dependencies were not installed properly. You specified that that program can attempt to automatically install such dependencies, but it failed. Please install these dependencies manually and try again. See ~/.gccbuild/log.txt for more information." << std::endl;
          exit(0);
          break;
        case 2:
          std::cout << "Error 2: This means that you tried to run buildgcc in an environment where the necessary dependencies were not installed properly. You specified that the program should not try to automatically install such dependencies, so it had nothing else to do and quit. Please install these dependencies manually and try again. See ~/.gccbuild/log.txt for more information." << std::endl;
          exit(0);
          break;

        default:
          std::cout << "Invalid error code. Try again with the right number. Error codes for this program range from -1 through 2, including 0." << std::endl;
          exit(0);
      }
    }
  }

  catch(std::exception &exception_check_params) { //This will execute if arguments were not recognised
    std::cout << "Exception while parsing arguments: " << exception_check_params.what() << std::endl;
    exit(-1);
  }
}