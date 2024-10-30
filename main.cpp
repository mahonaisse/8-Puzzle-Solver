#include <iostream>
#include <string>
#include "Problem.h"
#include "Tree.h"
#include "Node.h"

int main() {
    Problem p;
    p.create_state();

    Tree p_tree(&p);

    p_tree.create_goal_state();

    std::cout << "Uniform cost search: " << '\n';
    p_tree.uniform_cost_search();
}

/*
g++ main.cpp Problem.cpp Tree.cpp Node.cpp -Wall -Werror -o Puzzle.exe
*/