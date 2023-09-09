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
    //-- Definitions
    # define ENDL "\n"
    # define FAILED "\033[1m\033[38;2;255;0;0m[FAILED]\033[0m "
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
            std::mutex frameMutex;
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
            void convert(cv::Mat& _input);
            /**
             * @brief Method to Change Cursor Blinking State in Terminal
             */
            void changeBlinkingState();
            /**
             * @brief Method to Read Camera Frame and Show Image
             */
            void generate(const int& _cameraNumber, const int& _speedOption);
    };
# endif // __QMRLT_ASCII_IMAGE