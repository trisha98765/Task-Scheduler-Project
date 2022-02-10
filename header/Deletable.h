#ifndef DELETABLE_H
#define DELETABLE_H

class Deletable {
    // Removes the object from local storage (hard drive)
    virtual void delete() = 0;
}

#endif
