#include "Problem.h"

void Problem::create_state() {
    char typed_number;

    // Iterate through 2D array, assigning read in elements
    // to itself. Add elements to hashmap and assign indices.
    for (int row_it = 0; row_it < 3; ++row_it) {
        for (int col_it = 0; col_it < 3; ++col_it) {
            std::cin >> typed_number;
            problem_array_[row_it][col_it] = typed_number;
            problem_map_[typed_number] = {row_it, col_it};
        }
    }
    std::cout << '\n';
}

void Problem::print_state() {
    // Iterate through problem state array and print elements. 
    std::cout << "Printing array:" << '\n';
    for (int row_it = 0; row_it < 3; ++row_it) {
        for (int col_it = 0; col_it < 3; ++col_it) {
            std::cout << problem_array_[row_it][col_it] << ' ';
        }
        std::cout << '\n';
    }

    std::cout << '\n' << "Printing hashmap:" << '\n';
    char state[3][3];

    for (char char_it = '0'; char_it < '9'; ++char_it) {
        // Iterate through chars 0 to 8. Access indices from
        // hashmap and use indices to set element in array to char.
        state[problem_map_[char_it].row_pos][problem_map_[char_it].col_pos] = char_it;
    }

    for (int row_it = 0; row_it < 3; ++row_it) {
        for (int col_it = 0; col_it < 3; ++col_it) {
            std::cout << state[row_it][col_it] << ' ';
        }
        std::cout << '\n';
    }
}

void Problem::move_up() {
    // Get the 0 tile's position.
    int row_pos = problem_map_['0'].row_pos;
    int col_pos = problem_map_['0'].col_pos;

    // Validate if 0 tile can move up.
    if (row_pos - 1 < 0) {
        std::cout << "Can't move up." << '\n';
        return;
    }

    // Get tile to be swapped with 0 tile.
    char tile_above = problem_array_[row_pos - 1][col_pos];

    // Swap chars in problem state array.
    problem_array_[row_pos - 1][col_pos] = '0';
    problem_array_[row_pos][col_pos] = tile_above;
    
    // Swap chars in problem state map.
    problem_map_[tile_above] = {row_pos, col_pos};
    problem_map_['0'] = {row_pos - 1, col_pos};
}

void Problem::move_left() {

}

void Problem::move_right() {
    
}

void Problem::move_down() {
    
}

int Problem::get_euclidean_distance() {
    // char state[3][3];

    // for (char char_it = '0'; char_it < '9'; ++char_it) {
    //     // Iterate through chars 0 to 8. Access indices from
    //     // hashmap and use indices to set element in array to char.
    //     state[problem_map_[char_it].first][problem_map_[char_it].second] = char_it;
    // }
    return 0;
};