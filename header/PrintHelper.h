#include <ostream>
#include <string>

#ifndef PRINT_HELPER_H
#define PRINT_HELPER_H

#define ALIGN_LEFT (-1)
#define ALIGN_CENTER (0)
#define ALIGN_RIGHT (1)

void printFillerBlock(std::ostream& out, int width, char startChar, char fillChar, char endChar);
void printAlignedText(std::ostream& out, int width, char startChar, char endChar, std::string text, int alignment);

#endif // PRINT_HELPER_H
