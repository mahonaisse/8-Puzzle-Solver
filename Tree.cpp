#include "Tree.h"

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

int Tree::get_misplaced_tiles() const {
    int total_misplaced = 0;

    for (auto const& map_it: root_->state_map_) {
        // Access key of iterated element from problem state
        // hashmap.
        const int& key = map_it.first;

        if (key == 0) {
            // Do nothing in this iteration. Do not count the
            // 0 tile as a misplaced tile.
        }
        // Check if key exists in hashmap. If so, compare
        // values of indices. Otherwise, increment misplaced tiles.
        else if (goal_.state_map_.find(key) != goal_.state_map_.end(key)) {
            // Access members of value (indices struct) from
            // problem state hashmap.
            const int& row_it_tile = map_it.second.row_position;
            const int& col_it_tile =  map_it.second.col_position;

                // Access members of value from goal state hashmap 
                // using iterated element's key.
                const int& row_goal_tile = goal_.state_map_.at(key).row_position;
                const int& col_goal_tile = goal_.state_map_.at(key).col_position;

                // Compare values of indices.
                if (row_it_tile != row_goal_tile || col_it_tile != col_goal_tile) {
                    total_misplaced++;
                }
        }
        else {
            total_misplaced++;
        }
    }

    return total_misplaced;
};

float Tree::get_euclidean_distance() const {
    float total_distance = 0;
    // Use variables in calculations for better readability.
    float tile_distance = 0;
    float x_distance = 0;
    float y_distance = 0;

    for (auto const& map_it: root_->state_map_) {
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
                // Calculate Euclidean distance from problem state tile position
                // to goal state tile position. 
                
                // Separate these distance calculations for better readability
                // and also so sqrt() works.
                x_distance = pow(row_it_tile - row_goal_tile, 2);
                y_distance = pow(col_it_tile - col_goal_tile, 2);
                
                tile_distance = sqrt(x_distance + y_distance);
                
                total_distance += tile_distance;
            }
        }
    }

    return total_distance;
};

void Tree::uniform_cost_search() {
    root_->print_state();
};
void Tree::a_star_search_with_misplaced_tiles() {

};

void Tree::a_star_search_with_euclidean_distance() {
    
};