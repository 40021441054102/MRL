# ifndef __QMRLT_ASCII_IMAGE
    # include "asciiCamera.hpp"
    //-- Signal Handler
    void signalHandler(int signum) {
        std::cout << LOG "Received Signal " << signum << std::endl;
        system("tput cnorm");
        exit(0);
    }
    //-- Main
    int main(int argc, char** argv) {
        //-- Check Amount of Arguments
        if (argc != 3) {
            std::cout << FAILED "Specify Speed Option and Camera ID Please" ENDL;
            std::cout << LOG "Example : ./run SUPER_FAST 0" ENDL;
            return EXIT_FAILURE;
        }
        //-- Check Arguments
        // std::string mode;
        // int source;
        // mode = argv[2];
        // source = std::stoi(argv[3]);
        // std::cout << "DEBUG" ENDL;
        // if (mode != "SUPER_FAST" || mode != "FAST") {
        //     std::cout << FAILED "'" << mode << "' is Wrong Mode" ENDL;
        //     return EXIT_FAILURE;
        // }
        // if (source < 0) {
        //     std::cout << FAILED "Source Must be Higher than -1" ENDL;
        // }
        AsciiCamera obj;
        obj.generate(0, FAST);
    }
# endif // __QMRLT_ASCII_IMAGE