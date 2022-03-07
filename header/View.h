#include <ostream>
#include <vector>

#ifndef VIEW_H
#define VIEW_H

void printMain(std::ostream& out, std::vector<TaskList>& allLists, TaskList& unsorted);
void printList(std::ostream& out, TaskList& list);

#endif // VIEW_H
