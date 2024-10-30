#include "Problem.h"

void Problem::create_state() {
    int typed_number;

    // Iterate through 2D array, assigning read in elements
    // to itself. Add elements to hashmap and assign indices.
    for (int row_it = 0; row_it < size_; ++row_it) {
        for (int col_it = 0; col_it < size_; ++col_it) {
            std::cin >> typed_number;
            state_array_[row_it][col_it] = typed_number;
            state_map_[typed_number] = {row_it, col_it};
        }
    }
}

void Problem::print_state() const {
    // Iterate through problem state array and print elements. 
    for (int row_it = 0; row_it < size_; ++row_it) {
        for (int col_it = 0; col_it < size_; ++col_it) {
            std::cout << state_array_[row_it][col_it] << ' ';
        }
        std::cout << '\n';
    }
}

bool Problem::move_zero_tile(const char &move) {
    int row_change = 0;
    int col_change = 0; 

    if (move == 'u') {
        row_change = -1;
        col_change = 0;
    }
    else if (move == 'l') {
        row_change = 0;
        col_change = -1;
    }
    else if (move == 'r') {
        row_change = 0;
        col_change = 1;
    }
    else if (move == 'd') {
        row_change = 1;
        col_change = 0;
    }
    
    // Get position of 0 tile.
    const int& row_zero_tile = state_map_.at(0).row_position;
    const int& col_zero_tile = state_map_.at(0).col_position;

    // Get position of tile to switch with 0 tile.
    const int row_target_tile = row_zero_tile + row_change;
    const int col_target_tile = col_zero_tile + col_change;
    
    // Validate a move is within bounds.
    if (row_target_tile < 0 || row_target_tile >= size_
        || col_target_tile < 0 || col_target_tile >= size_) {
        return false;
    }

    // Get tile to be swapped with 0 tile.
    const int tile_above = state_array_[row_target_tile][col_target_tile];

    // Swap tiles in problem state array.
    state_array_[row_target_tile][col_target_tile] = 0;
    state_array_[row_zero_tile][col_zero_tile] = tile_above;
    
    // Swap tiles in problem state hashmap.
    state_map_[tile_above] = {row_zero_tile, col_zero_tile};
    state_map_[0] = {row_target_tile, col_target_tile};
    
    return true;
}