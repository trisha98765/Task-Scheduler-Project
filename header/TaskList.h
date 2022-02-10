#include iostream>

#include "Named.h"
#include "Deletable.h"

#ifndef TASKLIST_H
#define TASKLIST_H

using namespace std;

class TaskList : public Named, public Deletable {
    public:
        void delete();
};

#endif
