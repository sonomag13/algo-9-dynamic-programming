
/*
    63. Unique Paths II
    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

    The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

    Now consider if some obstacles are added to the grids. How many unique paths would there be?

    An obstacle and space is marked as 1 and 0 respectively in the grid.

    Example 1:
    Input: obstacleGrid = [[0,0,0],
                           [0,1,0],
                           [0,0,0]]
    Output: 2
    Explanation: There is one obstacle in the middle of the 3x3 grid above.
    There are two ways to reach the bottom-right corner:
    1. Right -> Right -> Down -> Down
    2. Down -> Down -> Right -> Right
    
    Example 2:
    Input: obstacleGrid = [[0,1],[0,0]]
    Output: 1
    
    Constraints:
    m == obstacleGrid.length
    n == obstacleGrid[i].length
    1 <= m, n <= 100
    obstacleGrid[i][j] is 0 or 1.
 */

#include <vector>

using namespace std; 

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        // check if there is an obstacle at the starting position
        int rowNum = obstacleGrid.size(); 
        int colNum = obstacleGrid[0].size(); 
        if (obstacleGrid[0][0]) {
            return 0; 
        }
        
        vector<vector<int>> pathNum(rowNum, vector<int>(colNum, 0));
        
        /**
         * initialize the top row nad left column
         * if there is an obstacle in the grid, then the rest element in the row
         * or colum should be zero
         **/
        // left colum
        for (int rowIdx = 0; rowIdx < rowNum; ++rowIdx) {
            if (obstacleGrid[rowIdx][0]) {
                break; 
            }
            else {
                pathNum[rowIdx][0] = 1; 
            }
        }        
        // top row
        for (int colIdx = 1; colIdx < colNum; ++colIdx) {
            if (obstacleGrid[0][colIdx]) {
                break; 
            }
            else{
                pathNum[0][colIdx] = 1; 
            }
        }
        
        /**
         * the transfer function is the same to unique path 
         * the only difference is that if [i, j] in the grid is an obstacle, 
         * the value of pathNum[i, j] should be zero since it cannot be arrived
         **/ 
        for (int rowIdx = 1; rowIdx < rowNum; ++rowIdx) {
            for (int colIdx = 1; colIdx < colNum; ++colIdx) {
                if (obstacleGrid[rowIdx][colIdx]) {
                    pathNum[rowIdx][colIdx] = 0; 
                }
                else {
                    pathNum[rowIdx][colIdx] = pathNum[rowIdx - 1][colIdx] + pathNum[rowIdx][colIdx - 1]; 
                }
            }            
        }
                
        return pathNum[rowNum - 1][colNum - 1]; 
        
    }
};