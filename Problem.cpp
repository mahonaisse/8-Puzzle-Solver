#include "Problem.h"

void Problem::create_state() {
    int typed_number;

    // Iterate through 2D array, assigning read in elements
    // to itself. Add elements to hashmap and assign indices.
    for (int row_it = 0; row_it < size_; ++row_it) {
        for (int col_it = 0; col_it < size_; ++col_it) {
            std::cin >> typed_number;
            problem_array_[row_it][col_it] = typed_number;
            problem_map_[typed_number] = {row_it, col_it};
        }
    }
    std::cout << '\n';
}

void Problem::print_state() const {
    // Iterate through problem state array and print elements. 
    std::cout << "Printing array:" << '\n';
    for (int row_it = 0; row_it < size_; ++row_it) {
        for (int col_it = 0; col_it < size_; ++col_it) {
            std::cout << problem_array_[row_it][col_it] << ' ';
        }
        std::cout << '\n';
    }

    std::cout << '\n' << "Printing hashmap:" << '\n';
    // Create temporary array for printing hashmap.
    int state[size_][size_];

    // Iterate through elements of hashmap with a (key, value).
    for (auto const& map_it: problem_map_) {
        // Access value of iterated element.
        const indices& position = map_it.second;
        // Use indices to set array element to key of iterated element.
        state[position.row_position][position.col_position] = map_it.first;
    }

    for (int row_it = 0; row_it < size_; ++row_it) {
        for (int col_it = 0; col_it < size_; ++col_it) {
            std::cout << state[row_it][col_it] << ' ';
        }
        std::cout << '\n';
    }
}

void Problem::move_zero_tile(const int& row_change, const int& col_change) {
    // Validate move is not diagonal or a jump.
    if (row_change != 0 && col_change != 0) {
        std::cout << "Invalid Move: Tiles must move up, down, left, or right." << '\n';
        return;
    }
    // Validate a tile will move.
    else if (row_change == 0 && col_change == 0) {
        std::cout << "Invalid Move: A tile must move." << '\n';
        return;
    }
    
    // Get position of 0 tile.
    const int& row_zero_tile = problem_map_.at(0).row_position;
    const int& col_zero_tile = problem_map_.at(0).col_position;

    // Get position of tile to switch with 0 tile.
    const int row_target_tile = row_zero_tile + row_change;
    const int col_target_tile = col_zero_tile + col_change;
    
    // Validate a move is within bounds.
    if (row_target_tile < 0 || row_target_tile >= size_
        || col_target_tile < 0 || col_target_tile >= size_) {
        std::cout << "Invalid Move: Movement is out of bounds." << '\n';
        return;
    }

    // Get tile to be swapped with 0 tile.
    const int tile_above = problem_array_[row_target_tile][col_target_tile];

    // Swap tiles in problem state array.
    problem_array_[row_target_tile][col_target_tile] = 0;
    problem_array_[row_zero_tile][col_zero_tile] = tile_above;
    
    // Swap tiles in problem state hashmap.
    problem_map_[tile_above] = {row_zero_tile, col_zero_tile};
    problem_map_[0] = {row_target_tile, col_target_tile};
    print_state();
}

int Problem::get_misplaced_tiles() const {
    int misplaced_counter = 0;

    for (auto const& map_it: problem_map_) {
        // Access key of iterated element from problem state
        // hashmap.
        const int& key = map_it.first;

        if (key == 0) {
            // Do nothing in this iteration. Do not count the
            // 0 tile as a misplaced tile.
        }
        // Check if key exists in hashmap. If so, compare
        // values of indices. Otherwise, increment misplaced tiles.
        else if (goal_map_.find(key) != goal_map_.end(key)) {
            // Access members of value (indices struct) from
            // problem state hashmap.
            const int& row_it_tile = map_it.second.row_position;
            const int& col_it_tile =  map_it.second.col_position;

                // Access members of value from goal state hashmap 
                // using iterated element's key.
                const int& row_goal_tile = goal_map_.at(key).row_position;
                const int& col_goal_tile = goal_map_.at(key).col_position;

                // Compare values of indices.
                if (row_it_tile != row_goal_tile || col_it_tile != col_goal_tile) {
                    misplaced_counter++;
                }
        }
        else {
            misplaced_counter++;
        }
    }

    return misplaced_counter;
};

int Problem::get_euclidean_distance() const {
    return 0;
};