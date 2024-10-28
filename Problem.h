#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <iostream>
#include <unordered_map>

class Problem {
    public:
        // Struct of two ints to be used in hashmaps below as indices mapped to chars/tiles.
        struct indices {
            int row_pos;
            int col_pos;
        };

        Problem() {
            // Initialize goal state hashmap.
            goal_map_['1'] = {0, 0};
            goal_map_['2'] = {0, 1};
            goal_map_['3'] = {0, 2};
            goal_map_['4'] = {1, 0};
            goal_map_['5'] = {1, 1};
            goal_map_['6'] = {1, 2};
            goal_map_['7'] = {2, 0};
            goal_map_['8'] = {2, 1};
            // 0 tile in arrays and maps represents the
            // empty space that other tiles can move into.
            goal_map_['0'] = {2, 2};
        }
        
        void create_state();
        void print_state();

        // These functions move the 0 tile.
        // All moves first check if the move is legal.
        void move_up();
        void move_left();
        void move_right();
        void move_down();

        int get_misplaced_tiles();
        int get_euclidean_distance();

    private:
        // Use a 2D array for swapping and finding adjacent tiles
        // to the empty tile.
        char problem_array_[3][3];

        // Use hashmaps to represent our states for constant runtime
        // every time we look for the 0 tile and legal moves.
        std::unordered_map<char, indices> problem_map_;
        std::unordered_map<char, indices> goal_map_;
};

#endif  // PROBLEM_H_


