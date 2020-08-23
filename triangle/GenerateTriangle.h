//
// Created by luther on 8/16/20.
//

#pragma once

#include <time.h>
#include <vector>

using namespace std;

vector<vector<int>> exampleTriangle() {
    vector<int> v0{2};
    vector<int> v1{3, 4};
    vector<int> v2{6, 5, 7};
    vector<int> v3{4, 1, 8, 3};
    return vector<vector<int>>{v0, v1, v2, v3};
}

vector<vector<int>> generateNHeightTriangle(size_t rowNum, uint64_t range) {
    vector<vector<int>> triangle;
    srand(time(NULL));
    for (size_t rowIdx = 0; rowIdx < rowNum; ++rowIdx) {
        vector<int> rowVec;
        size_t colNum = rowIdx + 1;
        for (size_t colIdx = 0; colIdx < colNum; ++colIdx) {
            // the random numbers are in the range of [0, range)
            rowVec.push_back(rand() % range);
        }
        triangle.push_back(rowVec);
    }
    return triangle;
}