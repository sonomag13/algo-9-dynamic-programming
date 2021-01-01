/*
    64. Minimum Path Sum
    Medium
    Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time.

    Example 1:
    Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
    Output: 7
    Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
    
    Example 2:
    Input: grid = [[1,2,3],[4,5,6]]
    Output: 12
    
    Constraints:
        m == grid.length
        n == grid[i].length
        1 <= m, n <= 200
        0 <= grid[i][j] <= 100
 */

#include <vector>

using namespace std; 

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        if (!grid.size()) {
            return 0;
        }
        if (!grid[0].size()) {
            return 0; 
        }
        int rowNum = grid.size();
        int colNum = grid[0].size(); 

        // boundary condition
        vector<vector<int>> pathSum(rowNum, vector<int>(colNum, 0));
        pathSum[0][0] = grid[0][0]; 

        /**
         * Boundary conditions
         * - left column: in this column, the only opntion is to
         *   move from the top neighbor
         * - top row: in this row, the only option is to move from 
         *   the left neighbot
         **/
        for (int rowIdx = 1; rowIdx < rowNum; ++rowIdx) {
            pathSum[rowIdx][0] = pathSum[rowIdx - 1][0] + grid[rowIdx][0];            
        }
        for (int colIdx = 1; colIdx < colNum; ++colIdx) {
            pathSum[0][colIdx] = pathSum[0][colIdx - 1] + grid[0][colIdx];
        }

        /**
         * Transfer function:
         * 
         *  cost sum[i, j] = min(cost sum[i - 1, j], cost sum[i, j - 1]) + cost[i, j]
         * 
         * - cost sum[i, j]: the min sum to get [i, j]
         * - cost sum[i - 1, j]: the min sum to get the upper neighbor
         * - cost sum[i, j - 1]: the min sum to get the left neighbor
         * - cost[i, j]: the cost to get [i, j]
         **/
        for (int rowIdx = 1; rowIdx < rowNum; ++rowIdx) {
            for (int colIdx = 1; colIdx < colNum; ++colIdx) {
                pathSum[rowIdx][colIdx] = grid[rowIdx][colIdx] + min(pathSum[rowIdx - 1][colIdx], 
                                                                     pathSum[rowIdx][colIdx - 1]); 
            }
        }

        return pathSum[rowNum - 1][colNum - 1]; 

    }

};