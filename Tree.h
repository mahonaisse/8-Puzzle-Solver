#ifndef TREE_H_
#define TREE_H_

#include "Problem.h"

class Tree {
    private:
        // Node struct to hold Problems and children.
        struct Node {
            Problem problem;
            Problem* up;
            Problem* down;
            Problem* left;
            Problem* right;

            int heuristic_cost;
            int actions_cost;

            // Constructor of Node to set root as a pointer to
            // parameterized Problem.
            Node(Problem p) : problem(p), up(nullptr), down(nullptr),
                              left(nullptr), right(nullptr),
                              heuristic_cost(0), actions_cost(0) {}
        };

        Node root_;
        Node* new_node(const Problem &);
    
    public:
        // Tree constructor to set parameterized Problem
        // as root node of tree.
        Tree(Problem& p) : root_(p) {}

        void create_goal_state();

        int get_misplaced_tiles() const;
        float get_euclidean_distance() const;

        void uniform_cost_search();
        void a_star_search_with_misplaced_tiles();
        void a_star_search_with_euclidean_distance();
    
    private:
        Problem goal_;
        int max_number_of_queued_nodes_;
};

#endif  // TREE_H_