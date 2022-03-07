#ifndef COLOR_MANAGER_H
#define COLOR_MANAGER_H

// Windows Colors
#ifdef WINDOWS
// From https://www.geeksforgeeks.org/color-cmd-command/
#define COLOR_BLACK   0
#define COLOR_RED     4
#define COLOR_YELLOW  6
#define COLOR_GREEN   2
#define COLOR_CYAN    3
#define COLOR_BLUE    1
#define COLOR_PURPLE  5
#define COLOR_WHITE   7
// ANSI Colors
#else
// From https://en.wikipedia.org/wiki/ANSI_escape_code#3-bit_and_4-bit
#define COLOR_BLACK   0
#define COLOR_RED     1
#define COLOR_YELLOW  3
#define COLOR_GREEN   2
#define COLOR_CYAN    6
#define COLOR_BLUE    4
#define COLOR_PURPLE  5
#define COLOR_WHITE   7
#endif

void setColor(int fg, int bg);
void clear();

#endif // COLOR_MANAGER_H
