//
// Created by luther on 9/14/20.
//

#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

template<typename t>
vector<vector<t>> getMatrix(const size_t sizeMatrix,
                            const size_t sizeSquare,
                            const pair<size_t, size_t> squarePosition) {

    vector<vector<t>> matrixOut;
    t base = 2;
    srand(time(NULL));
    for (size_t i = 0; i < sizeMatrix; ++i) {
        vector<t> row;
        for (size_t j = 0; j < sizeMatrix; ++j) {
            row.push_back(rand() % base);
        }
        matrixOut.push_back(row);
    }

    if(sizeSquare) {
        size_t rowIdx = squarePosition.first;
        size_t colIdx = squarePosition.second;
        assert((rowIdx + sizeSquare <= sizeMatrix) && (colIdx + sizeSquare <= sizeMatrix));
        for (size_t i = rowIdx; i < rowIdx + sizeSquare; ++i) {
            for (size_t j = colIdx; j < colIdx + sizeSquare; ++j) {
                matrixOut.at(i).at(j) = 1;
            }
        }
    }

    return matrixOut;

}

template <typename t>
void printMatrix(vector<vector<t>> matrix) {
    for (vector<t> row : matrix) {
        for (t val : row) {
            cout << " " << val << " ";
        }
        cout << endl;
    }
}

void printMatrix2(vector<vector<uint8_t>> matrix) {
    for (auto row : matrix) {
        for (auto val : row) {
            cout << " " << val << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int>> &matrix) {
        // write your code here

        // handle the empty case
        size_t rowNum = matrix.size();
        if (!rowNum) {
            return 0;
        }
        size_t colNum = matrix[0].size();
        if (!colNum) {
            return 0;
        }

        // define the dp space and apply boundary condition
        vector<vector<int>> dp(rowNum, vector<int>(colNum, -1));
        for (size_t rowIdx = 0; rowIdx < rowNum; ++rowIdx) {
            dp[rowIdx][0] = matrix[rowIdx][0];      // left column
        }
        dp[0] = matrix[0];                          // top row

        /**
         * start dp
         * transition function:
         * dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j1]) + 1
         */
        for (size_t rowIdx = 1; rowIdx < rowNum; rowIdx++) {
            for (size_t colIdx = 1; colIdx < colNum; colIdx++) {
                if (matrix[rowIdx][colIdx]) {
                    vector<int> squareSize{dp[rowIdx - 1][colIdx - 1], dp[rowIdx - 1][colIdx], dp[rowIdx][colIdx - 1]};
                    dp[rowIdx][colIdx] = *min_element(squareSize.begin(), squareSize.end()) + 1;
                }
                else {
                    dp[rowIdx][colIdx] = 0;
                }
            }
        }

        // search for the maximum square
        int maxSquare = 0;
        for (auto row : dp) {
            int maxSquareRow = *max_element(row.begin(), row.end());
            if (maxSquare < maxSquareRow) {
                maxSquare = maxSquareRow;
            }
        }
        return maxSquare * maxSquare;
    }
};