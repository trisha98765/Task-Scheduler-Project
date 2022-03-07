#include <ostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../header/Task.h"
#include "../header/TaskList.h"
#include "../header/ColorManager.h"
#include "../header/PrintHelper.h"
#include "../header/View.h"


#define VIEW_WIDTH 80
#define VIEW_HEIGHT 24

using std::ostream;
using std::vector;
using std::string;


void printMain(ostream& out, vector<TaskList>& allLists, TaskList& unsorted) {
    // Print title
    clear();
    printAlignedText(out, VIEW_WIDTH, '|', '|', "TASK PLANNER", ALIGN_CENTER);
    out << '\n';
    printFillerBlock(out, VIEW_WIDTH, '|', '=', '|');
    out << '\n';
    
    // Main content
    printAlignedText(out, VIEW_WIDTH / 2, '|', '|', "Your Lists", ALIGN_CENTER);
    printAlignedText(out, VIEW_WIDTH / 2, ' ', '|', "Your Unsorted Tasks", ALIGN_CENTER);
    out << '\n';
    printFillerBlock(out, VIEW_WIDTH / 2, '|', '-', '|');
    printFillerBlock(out, VIEW_WIDTH / 2, '-', '-', '|');
    out << '\n';
    
    // Print tasks
    int numLists = allLists.size();
    int numUnsorted = unsorted.getList().size();
    // Iterate through the full length of lists
    // Add an extra row for padding or messages
    for (int i = 0; i < max(numLists + 1, numUnsorted + 1); ++i) {
        // If there is are at least i lists
        if (i < numLists) {
            printAlignedText(
                out,
                (VIEW_WIDTH / 2),
                '|', '|',
                " * " + allLists.at(i).getName(),
                ALIGN_LEFT
            );
        }
        // No lists yet
        else if (i == 0) {
            printAlignedText(
                out,
                (VIEW_WIDTH / 2),
                '|', '|',
                "No task lists yet",
                ALIGN_CENTER
            );
        }
        // Empty slot
        else {
            printFillerBlock(out, VIEW_WIDTH / 2, '|', ' ', '|');
        }
        
        // If there is are at least i lists
        if (i < numUnsorted) {
            printAlignedText(
                out,
                (VIEW_WIDTH / 2),
                ' ', '|',
                " * " + unsorted.getList().at(i)->getName(),
                ALIGN_LEFT
            );
        }
        // No unsorted tasks yet
        else if (i == 0) {
            printAlignedText(
                out,
                (VIEW_WIDTH / 2),
                ' ', '|',
                "No unsorted tasks yet",
                ALIGN_CENTER
            );
        }
        // Empty slot
        else {
            printFillerBlock(out, VIEW_WIDTH / 2, ' ', ' ', '|');
        }
        
        out << '\n';
    }
    
    // Print footer
    printFillerBlock(out, VIEW_WIDTH, '|', '=', '|');
    out << '\n';
}


void printList(std::ostream& out, TaskList& list) {
    // Print title
    clear();
    printAlignedText(out, VIEW_WIDTH, '|', '|', "TASK LIST: " + list.getName(), ALIGN_CENTER);
    out << '\n';
    printFillerBlock(out, VIEW_WIDTH, '|', '=', '|');
    out << '\n';
    
    // Main content
    if (list.getList().size() > 0) {
        for (int i = 0; i < list.getList().size(); ++i) {
            printAlignedText(
                out,
                VIEW_WIDTH,
                '|', '|',
                " * " + list.getList().at(i)->getName(),
                ALIGN_LEFT
            );
            
            out << '\n';
        }
    } else {
        printAlignedText(
            out,
            VIEW_WIDTH,
            '|', '|',
            "No tasks in this list yet",
            ALIGN_CENTER
        );
        out << '\n';
    }
    
    // Print footer
    printFillerBlock(out, VIEW_WIDTH, '|', '=', '|');
    out << '\n';
}
