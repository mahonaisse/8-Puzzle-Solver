#ifndef TREE_H_
#define TREE_H_

#include <vector>

#include "Problem.h"

class Tree {
    private:
        // Node struct to hold Problems and children.
        struct Node {
            Problem* problem;

            Node* up;
            Node* down;
            Node* left;
            Node* right;

            bool explored;
            int heuristic_cost;
            int actions_cost;

            // Constructor of Node to set root as a pointer to
            // parameterized Problem.
            Node(const Problem& p) : problem(new Problem(p)), up(nullptr), down(nullptr),
                                    left(nullptr), right(nullptr),
                                    explored(false),
                                    heuristic_cost(0), actions_cost(0) {}
        };

        Node* root_;
        Node* new_node_(const Problem &);
    
    public:
        // Tree constructor to set parameterized Problem
        // as root node of tree.
        // Allocate a new Node object and set root_ to point to
        // that object. Allocation of Node uses constructor
        // above to set problem to p.
        Tree(const Problem& p) : root_(new Node(p)) {
            create_goal_state();
        }

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