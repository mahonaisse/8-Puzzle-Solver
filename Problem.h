#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <iostream>
#include <unordered_map>
#include <cmath>

class Problem {
    public:
        // Struct of two ints to be used in hashmaps below as indices mapped to chars/tiles.
        struct indices {
            int row_position;
            int col_position;
        };

        Problem() {
            // Initialize goal state hashmap.
            goal_map_[1] = {0, 0};
            goal_map_[2] = {0, 1};
            goal_map_[3] = {0, 2};
            goal_map_[4] = {1, 0};
            goal_map_[5] = {1, 1};
            goal_map_[6] = {1, 2};
            goal_map_[7] = {2, 0};
            goal_map_[8] = {2, 1};
            // 0 tile in arrays and maps represents the
            // empty space that other tiles can move into.
            goal_map_['0'] = {2, 2};
        }
        
        void create_state();
        void print_state() const;

        void move_zero_tile(const int &, const int &);

        int get_misplaced_tiles() const;
        float get_euclidean_distance() const;

    private:
        // Create constant int size at compile time
        // for arrays and iterations.
        static constexpr int size_ = 3;
        
        // Use a 2D array for swapping and finding adjacent tiles
        // to the empty tile.
        int problem_array_[size_][size_];

        // Use hashmaps to represent our states for constant runtime
        // every time we look for the 0 tile and legal moves.
        std::unordered_map<int, indices> problem_map_;
        std::unordered_map<int, indices> goal_map_;
};

#endif  // PROBLEM_H_