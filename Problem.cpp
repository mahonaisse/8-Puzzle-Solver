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

    // Iterate through numbers that should exist in hashmap.
    // Ex. A 3x3 array means there should be 0 to 2^3=8 in the hashmap.
    for (int num_it = 0; num_it < pow(2, size_) + 1; ++num_it) {
        // Access indices mapped to number from hashmap and use
        // indices to set array element to iterated number. 
        state[problem_map_.at(num_it).row_position][problem_map_.at(num_it).col_position] = num_it;
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
    if (row_target_tile < 0 || row_target_tile >= size_ || col_target_tile < 0 || col_target_tile >= size_) {
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
    return 0;
};

int Problem::get_euclidean_distance() const {
    return 0;
};