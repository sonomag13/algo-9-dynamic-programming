/*
    114. Unique Paths
    A robot is located at the top-left corner of a m x n grid.

    The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid.

    How many possible unique paths are there?

    Example
    Example 1:

    Input: n = 1, m = 3
    Output: 1	
    Explanation: Only one path to target position.
    Example 2:

    Input:  n = 3, m = 3
    Output: 6	
    Explanation:
        D : Down
        R : Right
        1) DDRR
        2) DRDR
        3) DRRD
        4) RRDD
        5) RDRD
        6) RDDR
    Notice
    m and n will be at most 100.
    The answer is guaranteed to be in the range of 32-bit integers
 */

#include <vector>

using namespace std; 

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        /**
         * the element at [i, j] in this matrix represents the count of 
         * the paths to get to that coordinate 
         **/ 
        vector<vector<int>> pathCount(m, vector<int>(n, 0)); 
        
        /**
         * boundary condition
         * - the elements on the top row should be 1 since the robot can 
         *   only enter these coordinates from its left neighbor
         * - the elements on the left column should be 1 since the robot
         *   can only enter these coordinate from its top neighbor
         **/ 
        for (int colIdx = 0; colIdx < n; ++colIdx) {
            pathCount[0][colIdx] = 1; 
        }
        for (int rowIdx = 0; rowIdx < m; ++rowIdx) {
            pathCount[rowIdx][0] = 1; 
        }
        
        /**
         * Ultimate goal: the unique path to get to [m - 1][n - 1], which depends
         * on how many unique ways to get to its neighbors on the top and left
         *             
         * Subtaks: for an arbitary with coordinate [i][j], the unique path to 
         * get there is the sum of unique paths to get to its top and left neighbors, 
         * i.e.
         *              paths[i][j] = paths[i - 1][j] + paths[i][j - 1]
         **/ 
        
        for (int rowIdx = 1; rowIdx < m; ++rowIdx) {
            for (int colIdx = 1; colIdx < n; ++colIdx) {
                pathCount[rowIdx][colIdx] = pathCount[rowIdx - 1][colIdx] + pathCount[rowIdx][colIdx - 1]; 
            }
        }
        
        return pathCount[m - 1][n - 1]; 
    }
};