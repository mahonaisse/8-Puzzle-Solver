#include <iostream>
#include <string>

#include "Problem.h"
#include "Tree.h"

// Run the command below to compile the program:
// g++ main.cpp Problem.cpp Tree.cpp -Wall -Werror -o Puzzle.exe
// Then run the program by typing .\Puzzle.exe and enter
// in your terminal.

// Type in your numbers 0-8 to create state.
// 3 numbers per line, such that you type
// 1 2 3 enter
// 4 5 6 enter
// 7 0 8 enter.

// Then type in your choice 0-3 and enter.
// 0 exits the program.
// 1 performs uniform cost search.
// 2 performs A* search with misplaced tile heuristic.
// 3 performs A* search with Euclidean distance heuristic.

// Searches can be run multiple times.

int main() {
    int choice;

    Problem p;
    std::cout << '\n';
    p.create_state();

    while (true) {
        Tree p_tree(p);

            std::cout << '\n' << "--- Menu ---" << '\n'
                      << "0 to exit the program." << '\n'
                      << "1 to perform uniform cost search." << '\n'
                      << "2 to perform A* search with misplaced tiles heuristic." << '\n'
                      << "3 to perform A* search with Euclidean distance heuristic." << '\n'
                      << '\n' << "Enter choice (0-3): ";
        std::cin >> choice;

        switch (choice) {
            case 0:
                exit(0);
            case 1:
                p_tree.search_for_solution('u');
                break;
            case 2:
                p_tree.search_for_solution('m');
                break;
            case 3:
                p_tree.search_for_solution('e');
                break;
        }

        // Clear cin for next while loop.
        std::cin.clear();
        std::cin.ignore(256, '\n');

    }   // End of while loop.
}