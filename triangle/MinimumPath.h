//
// Created by luther on 8/15/20.
//

#pragma once

#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
    Solution () {
    }

    ~Solution() = default;

    vector<int> findMinPathDFS(vector<vector<int>> triangle) {
        vector<vector<int>> allPaths;
        vector<int> path;
        vector<int> minPath;
        findAllPathDFS(triangle, 0, 0, path, allPaths);
        int minSum = INT_MAX;
        for (auto path : allPaths) {
            int curSum = accumulate(path.begin(), path.end(), 0);
            if (curSum < minSum) {
                minSum = curSum;
                minPath = path;
            }
        }
        return minPath;
    }

    /**
     * Example:
     *      triangle    |       sum
     * 2                |   2
     * 3, 4             |   5, 6
     * 6, 5, 7          |   11, 10, 13
     * 4, 1, 8, 3       |   15, 11, 18, 16
     */
    static vector<int> findMinPathDP(const vector<vector<int>>& triangle) {
        /**
         * the key point of using memoization method is to record (or memoize) the sum of previous path sum, such that
         * we can avoid compute the sum of the same path for multiple times.
         *
         * We keep two vectors
         * - a 1D vector to record the minimum sum of previous of the nodes in the previous level
         * - a 2D vector to record the delta of each step (such that we can reconstruct the min sum path)
         */

        // the initial value of the first row has only one option
        vector<int> preMemoSum{triangle[0][0]};
        vector<vector<pair<int, int>>> allPathDelta;
        pair<int, int> delta = make_pair(0, 0);
        allPathDelta.push_back(vector<pair<int, int>>{delta});

        for (int rowIdx = 1; rowIdx < triangle.size(); ++rowIdx) {
            vector<int> curMemoSum;
            vector<pair<int, int>> curDelta;
            for (int colIdx = 0; colIdx < rowIdx + 1; colIdx++) {
                /**
                 * Two possible previous node:
                 * - preNode1 in the upper level with the column index left shifted by 1
                 * - preNode2 in the upper level with the same column index
                 *          ...     pre sum 1   pre sum 2       ...
                 *                              current sum
                 */
                int minPreSum;
                pair<int, int> delta;
                if (colIdx - 1 < 0) {
                    // only pre sum 2 exists
                    minPreSum = preMemoSum[colIdx];
                    delta = make_pair(+1, 0);
                }
                else if (colIdx >= preMemoSum.size()) {
                    // only pre sum 1 exists
                    minPreSum = preMemoSum[colIdx - 1];
                    delta = make_pair(+1, +1);
                }
                else {
                    // both pre sum 1 and pre sum 2 exist
                    int preSumNode1 = preMemoSum[colIdx - 1];
                    int preSumNode2 = preMemoSum[colIdx];
                    if (preSumNode1 > preSumNode2) {
                        minPreSum = preSumNode2;
                        delta = make_pair(+1, 0);
                    }
                    else {
                        minPreSum = preSumNode1;
                        delta = make_pair(+1, +1);
                    }
                }
                curMemoSum.push_back(triangle[rowIdx][colIdx] + minPreSum);
                curDelta.push_back(delta);
            }
            preMemoSum = curMemoSum;
            allPathDelta.push_back(curDelta);
        }

        // get the index of the min sum
        size_t minSumColIdx = min_element(preMemoSum.cbegin(), preMemoSum.cend()) - preMemoSum.cbegin();

        // reconstruct the path
        vector<int> minSumPath;
        size_t rowIdx = triangle.size() - 1;
        size_t colIdx = minSumColIdx;
        for(size_t step = 0; step < triangle.size(); step++) {
            minSumPath.push_back(triangle[rowIdx][colIdx]);
            pair<int, int> delta = allPathDelta[rowIdx][colIdx];
            rowIdx -= delta.first;
            colIdx -= delta.second;
        }
        reverse(minSumPath.begin(), minSumPath.end());
        return minSumPath;
    }

    static void printPath(const string& notification, vector<int> vectIn) {
        /**
         * print out a path with a notification
         */
        cout << notification << "\n\t";
        for (auto itr = vectIn.begin(); itr < vectIn.end() - 1; ++itr) {
            cout << *itr << " -> ";
        }
        cout << vectIn[vectIn.size() - 1] << endl;
    }

private:
    void findAllPathDFS(const vector<vector<int>>& triangle, int rowIdx, int colIdx,
                        vector<int> path, vector<vector<int>>& allPaths) {
        /**
         * base case where the length of the path is equal to the height of the triangle
         */
        if (path.size() == triangle.size()) {
            allPaths.push_back(path);
            return;
        }
        // check if the col index is valid
        if (colIdx < 0 || colIdx >= triangle[rowIdx].size()) {
            return;
        }
        /**
         * keep searching, the indices of the next element could be:
         * - row + 1, col
         * - row + 1, col + 1
         */
        path.push_back(triangle[rowIdx][colIdx]);
        findAllPathDFS(triangle, rowIdx+1, colIdx, path, allPaths);
        findAllPathDFS(triangle, rowIdx+1, colIdx + 1, path, allPaths);
    }

};


