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
    # include <iostream>
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
# endif // __QMRLT_ASCII_IMAGE