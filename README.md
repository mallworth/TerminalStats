Description: This program enhances the macOS terminal interface by displaying an ASCII Apple logo and system hardware statistics. 

Instructions: Ensure the main file is located in your user directory or specify its path during compilation. Navigate to terminal settings -> shell -> startup, and enable 'Run Command'. For the command, type: `printf "\033c" && gcc main.c && ./a.out`. NOTE: I used Glass TTY VT220 while formatting the Apple logo. Using a different font will likely make it look distorted.

Author: Max Allworth-Miles

License: This project is licensed under the MIT License.

Font Credit: The font used in this project, Glass TTY VT220, can be found on github: https://github.com/svofski/glasstty. This font is licensed under The Unlicense. For more information, please refer to http://unlicense.org
