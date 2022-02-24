#include <string>
#include <vector>
#include "../header/Task.h"
#include "../header/TaskList.h"

using namespace std;

void byMonthDue(TaskList entry, string inputDate){
    for(int i = 0; i < entry.size(); i++){
        string temp = entry.at(i).getDueDate();
        string subTemp = temp.substr(0,2);
        if(subTemp == inputDate.substr(0,2){
            entry.at(i).print();  
        }
    }
}

void byClassification(TaskList entry, string classInput){ //prints based on classification
    for(int i = 0; i < entry.size(); i++){
        string tempClass = entry.at(i).getClassification();
        if(tempClass == classInput){
            entry.at(i).print(); 
        }
    }
}

void byPriority(Tasklist entry){ // we can change this to print out a range. Rn it just prints the highest priority (1)
    for(int i = 0; i < entry.size(); i++){
        int temp = entry.at(i).getPriority();
        if(temp == 1){
            entry.at(i).print();  
        }
    }
}
           

void byDueNext(TaskList entry, string expectedDate){ //prints based on the next 7 days worth of tasks
    string month = expectedDate.substr(0,2);
    string day = expectedDate.substr(2,4);
    for(int i = 0; i < entry.size(); i++){
        string temp = entry.at(i).getDueDate();
        string tempMonth = temp.substr(0,2);
        if(tempMonth == month){
            string tempDay = temp.at(2,4);
            if(day - tempDay <= 7){
               entry.at(i).print(); 
            }
        }
    }
}
          
