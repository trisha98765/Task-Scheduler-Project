#include "../header/Filter.h"
#include "../header/TaskList.h"
#include "../header/Task.h"
#include "../header/Goal.h"
#include <string>

using namespace std;

void filter(TaskList entry, int answer, string searchVal,std::ostream &out){
    std::stringstream output;
    if(answer == 1){
        for(int i = 0; i < entry.getList().size(); i++){
            Task *tempTask = dynamic_cast<Task *>(entry.getList().at(i));
            std::string temp = tempTask->getDueDate();
            std::string subTemp = temp.substr(0,2);
            if(subTemp == searchVal){
                tempTask->print(out);  
            }
        }
    }
    else if(answer == 2){
        for(int i = 0; i < entry.getList().size(); i++){
            Task *tempTask = dynamic_cast<Task *>(entry.getList().at(i));
            std::string tempClass = tempTask->getClassification();
            if(tempClass == searchVal){
                tempTask->print(out); 
            }
        }
    }
    else if(answer == 3){
        for(int i = 0; i < entry.getList().size(); i++){
             Task *tempTask = dynamic_cast<Task *>(entry.getList().at(i));
            int temp = tempTask->getPriority();
            if(temp == stoi(searchVal)){
                tempTask->print(out);  
            }
        }
    }
    else if(answer == 4){
        std::string month = searchVal.substr(0,2);
        std::string day = searchVal.substr(2,4);
        for(int i = 0; i < entry.getList().size(); i++){
            Task *tempTask = dynamic_cast<Task *>(entry.getList().at(i));
            std::string temp = tempTask->getDueDate();
            std::string tempMonth = temp.substr(0,2);
            if(tempMonth == month){
                std::string tempDay = temp.substr(2,4);
                int num1, num2;
                stringstream container(day);
                container >> num1;
                stringstream container2(tempDay);
                container2 >> num2;
              //  num1 = stoi(day);
                //num2 = stoi(tempDay);

                if(num1 - num2 <= 7){
                    tempTask->print(out); 
                }
            }
        }
    }   
}
