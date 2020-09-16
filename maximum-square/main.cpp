#include "Solution.h"

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {

    size_t sizeMatrix = 8;
    size_t sizeSquare = 4;
    pair<size_t, size_t> squarePosition{make_pair(3, 2)};

    vector<vector<uint8_t>> matrix = getMatrix<uint8_t>(sizeMatrix, sizeSquare, squarePosition);

    // printMatrix<uint8_t>(matrix);

    // printMatrix2(matrix);

    for (auto row : matrix) {
        for (auto val : row) {
            cout << " " << (int) val << " ";
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}