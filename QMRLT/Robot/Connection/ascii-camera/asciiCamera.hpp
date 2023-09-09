# ifndef __QMRLT_ASCII_IMAGE
    /**
     * @file asciiCamera.hpp
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Show Ascii Image in Terminal, Useful for ssg Without ssh -X
     * @date 2023-09-09
     * @copyright Copyright Mechatronics Research Laboratory (c) 2023 - 2027 
     */
    # define __QMRLT_ASCII_IMAGE
    //-- Include Needed Libraries
    # include <opencv4/opencv2/imgproc.hpp>
    # include <opencv4/opencv2/highgui.hpp>
    # include <sys/ioctl.h>
    # include <unistd.h>
    # include <iostream>
    # include <string>
    # include <chrono>
    # include <thread>
    //-- Check Operating System for Specific Escape Character
    # if defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__) || defined(__MACH__) || defined(macintosh) || defined(Macintosh)
        /**
         * @brief Unix-Based Operating System
         */
        # define IS_UNIX true
        /**
         * @brief Escape Character
         */
        std::string escChar = "\033[";
    # else
        /**
         * @brief Not Unix-Based Operating System
         */
        # define IS_UNIX false
        /**
         * @brief Escape Character
         */
        std::string escChar = "\1xb[";
    # endif // Check Operating System for Console Escape Character
    /**
     * @brief Speed Options 
     */
    enum SpeedOptions {
        /**
         * @brief Super Fast Method Using Multi Threading
         */
        SUPER_FAST,
        /**
         * @brief Faster than Wifi Connection
         */
        FAST
    };
    /**
     * @brief Class Definition of Colorful Characters
     */
    class Character {
        protected:
            /**
             * @brief Ascii Pixel String
             */
            char ascii_pixel;
            /**
             * @brief Structure to Store RGB's Value of Ascii Pixel
             */
            struct Color {
                int green;
                int blue;
                int red;
            };
            /**
             * @brief Object to Access RGB's Value of Ascii Pixel
             */
            Color color;
        public:
            /**
             * @brief Constructor
             */
            Character() noexcept;
            /**
             * @brief Method to Set RGB Value of Ascii Pixel
             * @param _blue Blue
             * @param _green Green
             * @param _red Red
             */
            void setRGB(int& _blue, int& _green, int& _red) noexcept;
    };
    /**
     * @brief Class Definition of Ascii Camera
     */
    class AsciiCamera : public Character {
        private:
            /**
             * @brief Ascii Pixel
             */
            Character _char;
            /**
             * @brief Structure to Store Terminal's Data
             */
            struct Terminal {
                bool blink;
                int rows;
                int cols;
            };
            /**
             * @brief Object to Access Terminal's Data
             */
            Terminal terminal;
            struct winsize _terminal;
        public:
            /**
             * @brief Constructor
             */
            AsciiCamera() noexcept;
            /**
             * @brief Method to Get Size of Terminal
             */
            void getTerminalSize() noexcept;
            /**
             * @brief Method to Convert Image into Ascii Background
             */
            void convert(cv::Mat& _input, const int& _speedOption);
            /**
             * @brief Method to Change Cursor Blinking State in Terminal
             */
            void changeBlinkingState();
    };
# endif // __QMRLT_ASCII_IMAGE