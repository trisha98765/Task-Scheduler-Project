#include <string>
#include "Renamable.h"

using namespace std;

void Renamable::setName(string name) {
    this->name = name;
}

string Renamable::getName() {
    return name;
}
