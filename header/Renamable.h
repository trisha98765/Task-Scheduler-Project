#include <string>

#ifndef NAMED_H
#define NAMED_H

using std::string;

class Named {
    protected:
        string name;
    public:
        void setName(string name);
        string getName();
}

#endif
