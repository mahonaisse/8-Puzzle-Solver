#include <iostream>
#include <string>

#include "Problem.h"
#include "Tree.h"

// g++ main.cpp Problem.cpp Tree.cpp -Wall -Werror -o Puzzle.exe

// Type in your numbers 0-8 to create state.
// 3 numbers per line, such that you type
// 1 2 3 enter
// 4 5 6 enter
// 7 0 8 enter.

// Then type in your choice 0-4 and enter.
// 0 exits the program.
// 1 performs uniform cost search.
// 2 performs A* search with misplaced tile heuristic.
// 3 performs A* search with Euclidean distance heuristic.

// Searches can be run multiple times.

int main() {
    int choice;

    Problem p;
    p.create_state();

    Tree p_tree(p);

    while (true) {
        std::cout << '\n' << "Enter choice: ";
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