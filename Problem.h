#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <iostream>
#include <unordered_map>

class Problem {
    public:
        // Struct of two ints to be used in hashmaps below in place of a 2D array.
        struct indices {
            int first;
            int second;
        };

        Problem() {
            // Initialize goal state hashmap. 0 is the empty tile.
            goal_state_['1'] = {0, 0};
            goal_state_['2'] = {0, 1};
            goal_state_['3'] = {0, 2};
            goal_state_['4'] = {1, 0};
            goal_state_['5'] = {1, 1};
            goal_state_['6'] = {1, 2};
            goal_state_['7'] = {2, 0};
            goal_state_['8'] = {2, 1};
            goal_state_['0'] = {2, 2};
        }
        
        void create_state();
        void print_state();

        int get_misplaced_tiles();
        int get_euclidean_distance();
    private:
        // Use hashmaps to represent our states for constant runtime
        // every time we look for the empty tile and legal moves.
        std::unordered_map<char, indices> problem_state_;
        std::unordered_map<char, indices> goal_state_;
};

#endif  // PROBLEM_H_


