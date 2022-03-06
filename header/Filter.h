#ifndef FILTER_H
#define FILTER_H
#include <string>
#include <vector>
#include <sstream>
#include "Task.h"
#include "TaskList.h"
#include "Goal.h"
#include "Menu.h"

void filter(TaskList entry, int answer, std::string searchVal,std::ostream &out);

#endif
