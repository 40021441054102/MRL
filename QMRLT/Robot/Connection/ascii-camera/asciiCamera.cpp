# ifndef __QMRLT_ASCII_IMAGE
    # include "asciiCamera.hpp"
    /**
     * @brief Character Constructor
     */
    Character::Character() noexcept(true) {
        ascii_pixel = ' ';
        color.green = 0;
        color.blue = 0;
        color.red = 0;
    }
    /**
     * @brief Method to Set RGB Value of Ascii Pixel
     * @param _blue Blue
     * @param _green Green
     * @param _red Red
     */
    void Character::setRGB(int& _blue, int& _green, int& _red) noexcept(true) {
        color.green = _green;
        color.blue = _blue;
        color.red = _red;
    }
    /**
     * @brief Method to Get Size of Terminal
     */
    void AsciiCamera::getTerminalSize() noexcept(true) {
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &_terminal);
        terminal.rows = _terminal.ws_row;
        terminal.cols = _terminal.ws_col;
    }
    /**
     * @brief AsciiCamera Constructor
     */
    AsciiCamera::AsciiCamera() noexcept(true) {
        terminal.blink = false;
        changeBlinkingState();
        getTerminalSize();
    }
    /**
     * @brief Method to Change Cursor Blinking State in Terminal
     */
    void AsciiCamera::changeBlinkingState() {
        if (terminal.blink == true) {
            terminal.blink = false;
            system("tput civis");
        } else {
            terminal.blink = true;
            system("tput cnorm");
        }
    }
    /**
     * @brief Method to Convert Image into Ascii Background
     */
    void AsciiCamera::convert(cv::Mat& _input, const int& _speedOption) {
        getTerminalSize();
        cv::resize(_input, _input, cv::Size(terminal.cols, terminal.rows), cv::INTER_LINEAR);
        for (int i = 0; i < _input.rows; i++) {
            for (int j = 0; j < _input.cols; j++) {
                color.blue = _input.at<cv::Vec3b>(i, j)[0];
                color.green = _input.at<cv::Vec3b>(i, j)[1];
                color.red = _input.at<cv::Vec3b>(i, j)[2];
                std::cout << escChar << "48;2;" << color.red << ";" << color.green << ";" << color.blue << "m" << ascii_pixel << escChar << "0m";
            }
        }
        std::cout << "\033[" << terminal.rows << "A\033[0G";
        std::chrono::milliseconds duration(1);
        std::this_thread::sleep_for(duration);
    }
# endif // __QMRLT_ASCII_IMAGE