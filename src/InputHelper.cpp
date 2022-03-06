#include <istream>
#include <ostream>
#include "../header/InputHelper.h"

using namespace std;

int readInt(istream& in, ostream& out) {
    int input;
    
    in >> input;
    
    while (!in.good()) {
        out << "Please enter an integer\n";
        in.clear();
        in.ignore(256, '\n');
    }
    
    return input;
}
