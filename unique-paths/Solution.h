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
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {        
        
        /**
         * allocate a 2D matrix with m row and n column for dp searching. 
         * transfer function:
         *      dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
         **/         
        vector<vector<int>> dp(m, vector<int>(n));
        
        // initialize dp at [0][0]
        dp[0][0] = 1;
        
        // apply the boundary condition of the top row
        for (size_t j = 1; j < n; ++j) {
            dp[0][j] = 1; 
        }
        
        // apply the boundary condidion of the left column
        for (size_t i = 1; i < m; ++i) {
            dp[i][0] = 1; 
        }
        
        /**
         * start dp process from [1][1] to [m-1][n-1]
         * Order: 
         * - from left to right
         * - from top to bottom
         */ 
        for (size_t i = 1; i < m; ++i) {
            for (size_t j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
            }
        }
        
        return dp[m-1][n-1]; 
        
    }
};