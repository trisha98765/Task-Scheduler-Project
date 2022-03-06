#include <ostream>
#include <string>
#include "../header/PrintHelper.h"


using std::ostream;
using std::string;


void printFillerBlock(ostream& out, int width, char startChar, char fillChar, char endChar) {
    out << startChar;
    for (int i = 0; i < width - 2; ++i) {
        out << fillChar;
    }
    out << endChar;
}


void printAlignedText(ostream& out, int width, char startChar, char endChar, string text, int alignment) {
    // Print the start character
    out << startChar;
    
    // Print spaces before the text
    if (alignment == ALIGN_RIGHT) {
        for (int i = 0; i < width - text.length() - 2; ++i) {
            out << ' ';
        }
    } else if (alignment == ALIGN_CENTER) {
        for (int i = 0; i < ((width - text.length()) / 2) - 1; ++i) {
            out << ' ';
        }
    }
    
    // Print the actual text
    out << text;
    
    // Print spaces after the text
    if (alignment == ALIGN_LEFT) {
        for (int i = 0; i < width - text.length() - 2; ++i) {
            out << ' ';
        }
    } else if (alignment == ALIGN_CENTER) {
        for (int i = 0; i < ((width - text.length()) / 2) - 1; ++i) {
            out << ' ';
        }
    }
    
    // Print an extra space if there's a rounding error
    if (alignment == ALIGN_CENTER && text.length() % 2 == 1) {
        out << ' ';
    }
    
    // Print the end character
    out << endChar;
}
