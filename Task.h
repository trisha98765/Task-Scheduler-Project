#include <iostream>
#include <vector>

#include "Named.h"
#include "Deletable.h"

#ifndef TASK_H
#define TASK_H

using namespace std;

class Task : public Named, public Deletable {
    public:
        void delete();
};

#endif
