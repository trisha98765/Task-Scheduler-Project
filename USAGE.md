Usage Instructions
==================
### To compile program using Linux:
1. Open terminal.
2. Move to Task-Scheduler-Project directory.
3. Type `g++ -g -O0 -fno-inline src/main.cpp src/Goal.cpp src/Menu.cpp src/Task.cpp src/TaskList.cpp src/Filter.cpp src/InputHelper.cpp src/ColorManager.cpp src/PrintHelper.cpp src/View.cpp -o Task-scheduler` to compile.
4. Type `./Task-scheduler` to open executable and begin using program.

### To create a task list:
1. Enter "1" to select "Create new list/edit existing list" from the menu.
2. Enter "1" to select "Create new list" from the menu.
3. Enter a name for the task list.
4. After choosing a new menu option, the task list will be visible under "Your Lists" in the box at the top.

### To edit a task list:
1. Enter "1" to select "Create new list/edit existing list" from the menu.
2. Enter "2" to select "Edit existing list" from the menu.
3. Enter the name of the task list you want to edit.
    * Enter 1 to edit the list name, enter the new name, then see the updated name in the box above.
    * Or enter 2 to remove a task, then enter the name of the task you want to remove.
    * Or enter 3 to add an existing task, then enter the name of the unsorted task you want to move to a list.
    * Or enter 4 to add a new task, then enter all the required information.

### To create a task:
1. Enter "2" on the main menu to select "Create new task/edit existing task."
2. Enter "1" to select "Create new task."
3. Enter all the information as prompted on the screen.
4. The task will be visible under "Your Unsorted Tasks" at the top of the screen.

### To edit a task:
1. Enter "2" on the main menu to select "Create new task/edit existing task."
2. Enter "2" to select "Edit existing task."
3. Enter the name of the task you want to edit, select from the list under "Your Unsorted Tasks" at the top of the screen or an error message will be printed.
4. Enter a number 1-8 corresponding to the menu presented on the screen to change different attributes of the task or enter 9 to go back.
5. Enter the new value as prompted by the screen.

### To delete a task:
1. Enter "2" on the main menu to select "Create new task/edit existing task."
2. Enter "3" to select "Delete task."
3. Enter the name of the task you want to delete, select from the list under "Your Unsorted Tasks" at the top of the screen or an error message will be printed.
4. As prompted by the screen, enter "Y" or "N" to delete or not delete the task. 
5. As prompted by the screen, enter "Y" or "N" to undo the deletion.
### To delete a task list:
1. Enter "1" to select "Create new list/edit existing list" from the menu.
2. Enter "3" to select "Delete list."
3. Enter the name of the list you want to delete, select from the list under "Your Lists" at the top of the screen or an error message will be printed.
4. As prompted by the screen, enter "Y" or "N" to delete or not delete the task list. 
5. As prompted by the screen, enter "Y" or "N" to undo the deletion.

### To print task lists:
1. Enter "3" to select "Print list" from the main menu.

### To filter by various criteria:
1. Enter "4" to select "Filter" from the main menu.
2. Enter "1" to filter Unsorted Tasks (the box on the right) or "2" to filter a task list (from the box on the left).
    * To filter unsorted tasks after entering "1": enter a number 1-4 to select a criteria and enter the criteria as prompted by the screen.
    * To filter a list after entering "2": enter a number 1-4 to select a criteria, enter the criteria as prompted by the screen and enter the list you wish to filter.
### To quit the program:
1. Enter "5" on the main menu.
