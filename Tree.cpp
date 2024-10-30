#include "Tree.h"

Tree::Node* Tree::new_node_(const Problem& p) {
    // Create and return a pointer to a new Node.
    Node *new_node = new Node(p);

    return new_node;
};

Tree::Node* Tree::new_node_(const Problem& p, const int& actions_cost) {
    // Create and return a pointer to a new Node.
    Node *new_node = new Node(p);
    
    // Creating child takes an action cost of 1.
    new_node->actions_cost = actions_cost + 1;

    // Total cost in uniform cost search is only the amount of actions to get to problem
    // state from current state. Every time a node is expanded, which is when a new_node_
    // is allocated, the child node's action cost is parent node's action cost + 1.

    return new_node;
};


void Tree::create_goal_state() {
    goal_.state_map_[1] = {0, 0};
    goal_.state_map_[2] = {0, 1};
    goal_.state_map_[3] = {0, 2};
    goal_.state_map_[4] = {1, 0};
    goal_.state_map_[5] = {1, 1};
    goal_.state_map_[6] = {1, 2};
    goal_.state_map_[7] = {2, 0};
    goal_.state_map_[8] = {2, 1};
};

// Pass in 'm' to calculate misplaced tiles heuristic,
// or 'e' to get Euclidean distance heuristic.
float Tree::get_heuristic_cost(const char &cost_type, const Problem& problem) const {
    float total_cost = 0;

    // Use variables in calculations for better readability.
    float tile_distance = 0;
    float x_distance = 0;
    float y_distance = 0;

    for (auto const& map_it: problem.state_map_) {
        // Access key of iterated element from problem state
        // hashmap.
        const int& key = map_it.first;

        if (key == 0) {
            // Do nothing in this iteration. Do not calculate
            // Euclidean distance of the 0 tile.
        }
        // Check if key exists in hashmap. If so, compare
        // values of indices and calculate distance.
        else if (goal_.state_map_.find(key) != goal_.state_map_.end(key)) {
            // Access members of value (indices struct) from
            // problem state hashmap.
            const int& row_it_tile = map_it.second.row_position;
            const int& col_it_tile =  map_it.second.col_position;

            // Access members of value from goal state hashmap 
            // using iterated element's key.
            const int& row_goal_tile = goal_.state_map_.at(key).row_position;
            const int& col_goal_tile = goal_.state_map_.at(key).col_position;

            // Compare values of indices. Calculate Euclidean distance
            // if any indices differ.
            if (row_it_tile != row_goal_tile || col_it_tile != col_goal_tile) {
                if (cost_type == 'm') {
                    ++total_cost;
                }
                else if (cost_type == 'e') {
                    // Calculate Euclidean distance from problem state tile position
                    // to goal state tile position. 
                    
                    // Separate these distance calculations for better readability
                    // and also so sqrt() works.
                    x_distance = pow(row_it_tile - row_goal_tile, 2);
                    y_distance = pow(col_it_tile - col_goal_tile, 2);
                    
                    tile_distance = sqrt(x_distance + y_distance);
                    
                    total_cost += tile_distance;
                }
            }
        }
        else if (cost_type == 'm') {
            ++total_cost;
        }
    }

    return total_cost;
};

// Pass in 'u' for uniform cost search,
// 'm' for A* search with misplaced tile heuristic,
// or 'e' for A* search with Euclidean distance heuristic.
void Tree::search_for_solution(const char &search_algorithm) {
    Node *chosen_node = nullptr;
    Node *leaf_node = nullptr;

    // Initialize private member variables to help with search functions.
    frontier_.clear();
    explored_map_.clear();
    solution_ = nullptr,
    max_number_of_queued_nodes_ = 1,
    total_nodes_created = 1,
    frontier_it_index_ = 0,

    // Initialize the frontier using the initial state of problem.
    frontier_.push_back(root_);

    // While loop until solution is found.
    while (true) {
        // If front is empty then return failure.
        if (frontier_.empty() == true) {
            return;
        }

        // Choose a leaf node and remove it from the frontier.
        // Leaf nodes are sorted into the frontier if they were not explored already, with the
        // first Node having the lowest cost. If leaf node and a node in frontier have the 
        // same costs, the leaf node is added to the frontier after the node already in the
        // frontier.
        chosen_node = frontier_.front();
        frontier_.erase(frontier_.begin());
        --max_number_of_queued_nodes_;

        std::cout << "--- Expanding node --" << '\n';
        chosen_node->problem->print_state();

        std::cout << "--- Node details ---" << '\n';
        std::cout << "Actions cost: " << chosen_node->actions_cost << '\n';
        std::cout << "Heuristic cost: " << chosen_node->heuristic_cost << '\n';
        std::cout << "Total cost: " << chosen_node->total_cost << '\n';
        if (chosen_node->parent != nullptr) {
            std::cout << "String in hashmap: " << chosen_node->map_key_ << '\n';
            std::cout << "Parent string in hashmap: " << chosen_node->parent->map_key_ << '\n';
        }
        std::cout << "--- Tree details ---" << '\n';
        std::cout << "Maximum queue size: " << max_number_of_queued_nodes_ << '\n';
        std::cout << "Total nodes created: " << total_nodes_created << '\n';
        std::cout << "Frontier size: " << frontier_.size() << '\n';

        // If the node contains a goal state then return the corresponding solution.
        if (get_heuristic_cost('m', *chosen_node->problem) == 0) {
            // chosen_node->problem->print_state();
            solution_ = chosen_node;
            std::cout << '\n' << "Goal state found!" << '\n';
            return;
        }
        else if (chosen_node->actions_cost > 80) {
            std::cout << "Max actions taken. There is no solution. " << '\n';
            return;
        }
        else {
            // chosen_node->problem->print_state();
        }

        // Adds node to explored set. Do this after checking if node exists
        // in the hashmap.
        
        std::cout << "--- Possible moves ---" << '\n';
        // Explores moves in 4 directions.
        for (int moves_it = 0; moves_it < 4; ++moves_it) {
            leaf_node = new_node_(*chosen_node->problem, chosen_node->actions_cost);

            if (leaf_node->problem->move_zero_tile(moves_[moves_it]) == true) {
                std::cout << "Direction " << moves_[moves_it] << " found." << '\n';
                switch (moves_it) {
                    case 0:
                        chosen_node->up = leaf_node;
                        leaf_node->parent = chosen_node;
                        break;
                    case 1:
                        chosen_node->left = leaf_node;
                        leaf_node->parent = chosen_node;
                        break;
                    case 2:
                        chosen_node->down = leaf_node;
                        leaf_node->parent = chosen_node;
                        break;
                    case 3:
                        chosen_node->right = leaf_node;
                        leaf_node->parent = chosen_node;
                        break;
                }

                // Update any costs for search algorithm. Use
                // total cost of a leaf node for sorting into frontier later.
                if (search_algorithm == 'u') {
                    leaf_node->total_cost = leaf_node->actions_cost;
                }
                else if (search_algorithm == 'm') {
                    leaf_node->heuristic_cost = get_heuristic_cost('m', *leaf_node->problem);
                    leaf_node->total_cost = leaf_node->actions_cost + leaf_node->heuristic_cost;
                }
                else if (search_algorithm == 'e') {
                    leaf_node->heuristic_cost = get_heuristic_cost('e', *leaf_node->problem);
                    leaf_node->total_cost = leaf_node->actions_cost + leaf_node->heuristic_cost;
                }

                // Reads node expanded array into a string to check against or to be put
                // into explored_map__ hashmap.
                array_to_string_key.clear();

                for (int row_it = 0; row_it < goal_.size_; ++row_it) {
                    for (int col_it = 0; col_it < goal_.size_; ++col_it) {
                        array_to_string_key += leaf_node->problem->state_array_[row_it][col_it];
                    }
                } 

                // Add the resulting nodes to the frontier. If only chosen not is not in
                // frontier or explored set.
                if (explored_map_.count(array_to_string_key) == 0) {
                    std::cout << "Added new leaf node with cost " << leaf_node->total_cost << " to map." << '\n';
                    explored_map_[array_to_string_key] = true;
                    leaf_node->map_key_ = array_to_string_key;
                    ++max_number_of_queued_nodes_;
                    ++total_nodes_created;
                    child_nodes_[moves_it] = leaf_node;
                }
            }
        }

        std::cout << "-- Sorting details ---" << '\n';
        // Iterate through leaf nodes to sort into frontier. Leaf nodes are only added to frontier
        // if they are not in the explored set.
        for (int array_it = 0; array_it < 4; ++array_it) {
            if (child_nodes_[array_it] != nullptr) {       
                // Sorts child into frontier by cost.
                // Push back node if frontier is empty or if child node to sort has a larger or equal
                // cost than last node in frontier, otherwise iterate through frontier to sort child node
                // into frontier.
                std::cout << "Sorting... " << '\n';
                if (frontier_.empty() || child_nodes_[array_it]->total_cost >= frontier_.back()->total_cost) {
                    frontier_.push_back(child_nodes_[array_it]);
                    std::cout << "Added to back of frontier." << '\n';
                    child_nodes_[array_it] = nullptr;
                }
                else {
                    frontier_it_index_ = 0;
                    for (const auto & frontier_it : frontier_) {
                        // std::cout << "Iteration " << frontier_it << " of " << frontier_.size() << '\n';
                        // std::cout << "Checking " << child_nodes_[array_it]->total_cost << " against " << frontier_.at(frontier_it_index_)->total_cost << '\n';
                        ++frontier_it_index_;
                        if (child_nodes_[array_it]->total_cost < frontier_it->total_cost) {
                            frontier_.insert(frontier_.begin() + frontier_it_index_, child_nodes_[array_it]);
                            
                            std::cout << "Added node with cost " << child_nodes_[array_it]->total_cost << " in position "
                            << frontier_it_index_ << " of frontier of size " << frontier_.size() << "." << '\n' << '\n';


                            // Removes nodes from child nodes array to prevent readding leaf_node in
                            // while loop from previous expansion. 
                            child_nodes_[array_it] = nullptr;
        
                            // Child node sorted into frontier, break out of loop.
                            break;
                        }
                    }
                }
            }
        }
        std::cout << '\n' << '\n';
    }   // End of while loop.
};