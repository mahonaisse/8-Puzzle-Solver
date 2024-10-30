#ifndef TREE_H_
#define TREE_H_

#include "Problem.h"
#include <vector>

class Tree {
    public:
        // Node to hold Problems and children.
        struct Node {
            Problem* problem;
            std::vector<Problem *> child;

            int heuristic_cost_;
            int actions_cost_;

            // Constructor of Node struct to set root as a pointer to
            // parameterized Problem.
            Node(Problem* problem) : problem(problem) {}
        };

        // Tree constructor to set parameterized Problem
        // as root node of tree.
        Tree(Problem* problem) : root_(problem) {}

        void create_goal_state();

        int get_misplaced_tiles() const;
        float get_euclidean_distance() const;

        void uniform_cost_search();
        void a_star_search_with_misplaced_tiles();
        void a_star_search_with_euclidean_distance();
    private:
        Node root_;
        Problem goal_;
        int max_number_of_queued_nodes_;
};

#endif  // TREE_H_