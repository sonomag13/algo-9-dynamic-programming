//
// Created by luther on 9/14/20.
//

#pragma once

#include <iostream>
#include <vector>
#include <cassert>

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
