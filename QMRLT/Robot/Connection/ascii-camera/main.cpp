# ifndef __QMRLT_ASCII_IMAGE
    # include "asciiCamera.hpp"
    //-- Main
    int main(int argc, char** argv) {
        if (argc != 3) {
            std::cout << FAILED "Specify Speed Option and Camera ID Please" ENDL;
            return EXIT_FAILURE;
        }
        AsciiCamera obj;
        obj.generate(0, FAST);
    }
# endif // __QMRLT_ASCII_IMAGE