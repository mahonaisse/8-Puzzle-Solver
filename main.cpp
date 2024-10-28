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

    while (in_loop) {
        std::cout << '\n' << "Enter choice: ";
        // std::cout << '\n'
        // << "0. Exit loop" << '\n'
        // << "1. Move up" << '\n'
        // << "2. Move left" << '\n'
        // << "3. Move right" << '\n'
        // << "4. Move down" << '\n'
        // << "5. Get misplaced tiles" << '\n'
        // << "6. Get Euclidean distance" << '\n' << '\n';
        std::cin >> choice;
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
            case 5:
                // Get number of misplaced tiles of problem state to goal state.
                std::cout << "Misplaced tiles " << p.get_misplaced_tiles() << '\n';
                break;
            case 6:
                // Get Euclidean distance of problem state to goal state.
                std::cout << "Euclidean distance " << p.get_euclidean_distance() << '\n';
                break;
        }
        std::cin.clear();
        std::cin.ignore(256, '\n');
    }
}

/*
g++ main.cpp Problem.cpp Tree.cpp Node.cpp -Wall -Werror -o Puzzle.exe
*/