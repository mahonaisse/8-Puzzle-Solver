#ifndef TREE_H_
#define TREE_H_

#include "Problem.h"

class Tree {
    public:
        // Constructor to initialize root with problem
        Tree(Problem p) : root(&p), left(nullptr), right(nullptr) {}

        void uniform_cost_search();
        void a_star_search_with_misplaced_tiles();
        void a_star_search_with_euclidean_distance();
    private:
        Problem* root;
        Problem* left;
        Problem* right;

        int heuristic_cost_;
        int actions_cost_;
        int max_number_of_queued_nodes_;
};

#endif  // TREE_H_