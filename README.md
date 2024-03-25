Description: This program enhances the macOS terminal interface by displaying an ASCII Apple logo and system hardware statistics. 

Instructions: In your TerminalStats directory, type `gcc -o terminal_stats main.c` to compile the program. Then type `sudo mv terminal_stats /usr/local/bin` to move the program so it can be executed from any location in your terminal environment. Navigate to Terminal settings (`⌘,`) and drag terminal_profile.terminal into your terminal profiles list. Go to the Shell tab, enable 'Run Command', and type `printf "\033c" && terminal_profile`. Now the terminal_stats program will be run anytime you open a new terminal window, and can be re-run by typing `terminal_stats`.

Author: Max Allworth-Miles

License: This project is licensed under the MIT License.

Font Credit: The font used in this project, Glass TTY VT220, can be found on github: https://github.com/svofski/glasstty. This font is licensed under The Unlicense. For more information, please refer to http://unlicense.org

ASCII Art Credit: [Tony Wu](https://www.pinterest.com/pin/593419688424075562/) on [Pinterest](https://www.pinterest.com/)