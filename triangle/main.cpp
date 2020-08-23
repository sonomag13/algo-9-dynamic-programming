/**
    109. Triangle
    Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

    Example
    Example 1:

    Input the following triangle:
    [
         [2],
        [3,4],
       [6,5,7],
      [4,1,8,3]
    ]
    Output: 11
    Explanation: The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
    Example 2:

    Input the following triangle:
    [
         [2],
        [3,2],
       [6,5,7],
      [4,4,8,1]
    ]
    Output: 12
    Explanation: The minimum path sum from top to bottom is 12 (i.e., 2 + 2 + 7 + 1 = 12).
    Notice
    Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
  */

#include <iostream>
#include <vector>

#include "GenerateTriangle.h"
#include "MinimumPath.h"

using namespace std;

int main() {

    // define the vector
    // vector<vector<int>> triangle{exampleTriangle()};
    size_t triangleHeight = 30;
    size_t numRange = triangleHeight * 100;
    vector<vector<int>> triangle{generateNHeightTriangle(triangleHeight, numRange)};

    Solution minPathSolution;

    // solution by dfs, which stops working when the triagnle height is larger than 20
    cout << "starting find the path by DFS" << endl;
    vector<int> minPathDFS = minPathSolution.findMinPathDFS(triangle);
    Solution::printPath("\nmin path found by DFS: ", minPathDFS);

    // solution by dynamic programming
    cout << "starting find the path by DP" << endl;
    vector<int> minPathDP = minPathSolution.findMinPathDP(triangle);
    Solution::printPath("\nmin path found by DP: ", minPathDP);

    return 0;
}
