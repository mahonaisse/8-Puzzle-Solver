#ifndef TREE_H_
#define TREE_H_

#include <vector>
#include <unordered_map>

#include "Problem.h"

class Tree {
    private:
        // Node struct to hold Problems and children.
        struct Node {
            Problem* problem;

            Node* parent;
            Node* up;
            Node* down;
            Node* left;
            Node* right;

            std::string map_key_;
            float total_cost;
            float heuristic_cost;
            int actions_cost;
            char move_char;

            // Constructor of Node to set root as a pointer to
            // parameterized Problem.
            Node(const Problem& p) : problem(new Problem(p)),
                                     parent(nullptr),
                                     up(nullptr),
                                     down(nullptr),
                                     left(nullptr),
                                     right(nullptr),
                                     total_cost(0),
                                     heuristic_cost(0),
                                     actions_cost(0) {}
        };

        Node* root_;
        Node* new_node_(const Problem &);
        Node* new_node_(const Problem &, const int &);
    
    public:
        // Tree constructor to set parameterized Problem
        // as root node of tree.
        // Allocate a new Node object and set root_ to point to
        // that object. Allocation of Node uses constructor
        // above to set problem to p.
        Tree(const Problem& p) : root_(new Node(p)),
                                 solution_(nullptr),
                                 max_number_of_queued_nodes_(1),
                                 total_nodes_created(1),
                                 frontier_it_index_(0),
                                 child_nodes_{nullptr, nullptr, nullptr, nullptr} {
            create_goal_state();
        }

        void search_for_solution(const char &);
    private:
        // TODO:
        // Create a goal state from any set of unique numbers that can be sorted.
        // Ensure last element in goal state array is always a 0.
        void create_goal_state();

        void print_details(const Node &) const;
        void print_solution() const;

        float get_heuristic_cost(const char &, const Problem &) const;
        
        Problem goal_;

        // Node pointer gets updated at the end of search functions.
        // Use this to print solutions from initial state to goal state!
        Node* solution_;

        // Has to be long long unsigned int to compared against vector.size().
        long long unsigned int max_number_of_queued_nodes_;
        int total_nodes_created;

        std::vector<Node *> frontier_;
        // Int to help index through vector.
        int frontier_it_index_;

        // Use array of size 4 to hold resulting nodes from expansion to add to frontier.
        Node* child_nodes_[4];

        std::unordered_map<std::string, bool> explored_map_;
        // String to use for explored hashmap.
        std::string array_to_string_key;

        // Array of 4 moves to iterate through to reduce repeating lines for expanding a node.
        const char moves_[4] = {'u', 'l', 'd', 'r'};
};

#endif  // TREE_H_