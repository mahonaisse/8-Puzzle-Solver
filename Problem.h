#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <iostream>
#include <unordered_map>
#include <cmath>

class Problem {
    public:
        // Struct of two ints to be used in hashmaps below
        // as indices mapped to ints/tiles.
        struct indices {
            int row_position;
            int col_position;
        };

        friend class Tree;
        
        void create_state();
        void print_state() const;

        bool move_zero_tile(const char &);

        int get_misplaced_tiles() const;
        float get_euclidean_distance() const;

    private:
        // Create constant int size at compile time
        // for arrays and iterations.
        static constexpr int size_ = 3;
        
        // Use a 2D array for swapping and finding adjacent tiles
        // to the empty tile.
        int state_array_[size_][size_];

        // Use hashmaps to represent our states for constant runtime
        // every time we look for the 0 tile and legal moves.
        std::unordered_map<int, indices> state_map_;
};

#endif  // PROBLEM_H_