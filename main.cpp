#include <iostream>
#include <string>
#include "Problem.h"
#include "Tree.h"
#include "Node.h"


int main() {
    int choice;
    bool in_loop = true;

    Problem p;
    p.create_state();

    // Type in your numbers 0-8 to create state.
    // 3 numbers per line, such that you type
    // 1 2 3 enter
    // 4 5 6 enter
    // 7 0 8 enter.

    // Then type in your choice 0-4 and enter to exit or 
    // move the tiles. It will always calculate and display
    // heuristic costs.

    while (in_loop) {
        std::cout << '\n' << "Enter choice: ";
        std::cin >> choice;

        // Clear terminal
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Previous choice: " << choice << '\n' << '\n';

        switch (choice) {
            case 0:
                in_loop = false;
                break;
            case 1:
                // Move tile up 1.
                p.move_zero_tile(-1, 0);
                break;
            case 2:
                // Move tile left 1.
                p.move_zero_tile(0, -1);
                break;
            case 3:
                // Move tile right 1.
                p.move_zero_tile(0, 1);
                break;
            case 4:
                // Move tile down 1.
                p.move_zero_tile(1, 0);
                break;
        }

        // Outputs
        p.print_state();
        // Get number of misplaced tiles of problem state to goal state.
        std::cout << '\n' << "Misplaced tiles: " << p.get_misplaced_tiles() << '\n';
        // Get Euclidean distance of problem state to goal state.
        std::cout << "Euclidean distance: " << p.get_euclidean_distance() << '\n';

        // Clear cin for next while loop.
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
}

/*
g++ main.cpp Problem.cpp Tree.cpp Node.cpp -Wall -Werror -o Puzzle.exe
*/