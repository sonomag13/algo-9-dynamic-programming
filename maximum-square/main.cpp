#include "Solution.h"

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {

    size_t sizeMatrix = 8;
    size_t sizeSquare = 4;
    pair<size_t, size_t> squarePosition{make_pair(3, 2)};

    vector<vector<int>> matrix = getMatrix<int>(sizeMatrix, sizeSquare, squarePosition);

    // printMatrix<uint8_t>(matrix);

    // printMatrix2(matrix);

    for (auto row : matrix) {
        for (auto val : row) {
            cout << " " << (int) val << " ";
        }
        cout << endl;
    }

    Solution solution;
    size_t maxArea = solution.maxSquare(matrix);

    cout << "max area = " << maxArea << endl;

    return EXIT_SUCCESS;
}