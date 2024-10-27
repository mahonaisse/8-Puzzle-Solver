#include "Problem.h"

void Problem::create_state() {

}

void Problem::print_state() {
    char state[3][3];

    for (char char_it = '0'; char_it < '9'; ++char_it) {
        // Iterate through chars 0 to 8. Access indices from
        // hashmap and use indices to set element in array to char.
        state[goal_state_[char_it].first][goal_state_[char_it].second] = char_it;
    }

    // Iterate through array and print elements. 
    for (int row_it = 0; row_it < 3; ++row_it) {
        for (int col_it = 0; col_it < 3; ++col_it) {
            std::cout << state[row_it][col_it] << ' ';
        }
        std::cout << '\n';
    }
}

int Problem::get_misplaced_tiles() {
    return 0;
}

int Problem::get_euclidean_distance() {
    return 0;
};