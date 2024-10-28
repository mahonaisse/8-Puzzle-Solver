#include <iostream>
#include <string>
#include "Problem.h"
#include "Tree.h"
#include "Node.h"

using namespace std;

int main() {
    Problem p;
    p.create_state();
    p.move_up();
    p.print_state();
}

/*
g++ main.cpp Problem.cpp Tree.cpp Node.cpp -Wall -Werror -o Puzzle.exe
*/