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
# endif // __QMRLT_ASCII_IMAGE