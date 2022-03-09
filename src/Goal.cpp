#include <string>
#include "../header/Goal.h"

using namespace std;

Goal::Goal(){
    name = "";
}
Goal::Goal(string s){
    name = s;
}
void Goal::setName(string s){
    name = s;
}
string Goal::getName(){
    return name;
}
