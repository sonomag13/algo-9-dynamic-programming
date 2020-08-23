#include <iostream>
#include <unordered_map>
#include <inttypes.h>

#define MAX_NUM UINT64_MAX
// #define __STDC_FORMAT_MACROS

using namespace std;

uint64_t fib(size_t, unordered_map<int, uint64_t>&, bool&);
bool validateFibArray(const unordered_map<int, uint64_t>&);

int main() {

    // number of the fibonacci numbers
    uint64_t n{100};

    // memoize the calculation by unordered map
    unordered_map<int, uint64_t> fibMemo;

    for (size_t i = 1; i < n; i++) {
        bool flagExceed{false};
        uint64_t fibNum = fib(i, fibMemo, flagExceed);
        char notice[1024];
        if (flagExceed) {
            sprintf(notice, "fib(%zu) exceeds the limit of uint64_t", i);
            cout << notice << endl;
        }
        else {
            sprintf(notice, "fib(%zu) = %" PRIu64, i, fibNum);
            cout << notice << endl;
        }
    }

    bool isValidFibNum = validateFibArray(fibMemo);
    cout << "is it a valid fibonacci array? " << (isValidFibNum ? "yes" : "no") << endl;

    return EXIT_SUCCESS;
}

uint64_t fib(size_t i, unordered_map<int, uint64_t>& fibMemo, bool& flagExceed) {
    // base cases
    if (i == 1) {
        fibMemo.insert(make_pair(1, 1));
        return 1;
    }
    if (i == 2) {
        fibMemo.insert(make_pair(1, 1));
        return 1;
    }
    if (flagExceed) {
        return 0;
    }
    if (fibMemo.find(i) != fibMemo.end()) {
        return fibMemo.at(i);
    }
    else {
        uint64_t fibNum1{fib(i - 1, fibMemo, flagExceed)};
        uint64_t fibNum2{fib(i - 2, fibMemo, flagExceed)};
        /*
         * null cases:
         * - any of the returned fib values is null
         * - the sum of the return fib values exceeds uint64_t
         */
        if (!fibNum1 || !fibNum2 || (MAX_NUM - fibNum1 < fibNum2)) {
            fibMemo.insert(make_pair(i, 0));
            flagExceed = true;
            return 0;
        }
        // the sum of return fib values is within uint64
        uint64_t fibNum = fibNum1 + fibNum2;
        fibMemo.insert(make_pair(i, fibNum));
        return fibNum;
    }
}

bool validateFibArray(const unordered_map<int, uint64_t>& fibMemo) {
    size_t num = fibMemo.size();
    // empty map is treated as a false case
    if (num == 0) {
        return false;
    }
    // only 1 element, which must be 1
    if (num == 1) {
        if (fibMemo.at(1) == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    // 2 elements, and both of them must be 1
    if (num == 2) {
        if (fibMemo.at(1) == 1 && fibMemo.at(2) == 1) {
            return true;
        }
        else {
            return false;
        }
    }
    // more than 3 elements
    bool isFibArray = true;
    for (size_t i = 3; i < num; i++) {
        uint64_t val = fibMemo.at(i);
        if (!val) {
            break;
        }
        if (val - fibMemo.at(i - 1) != fibMemo.at(i - 2)) {
            isFibArray = false;
            break;
        }
    }
    return isFibArray;
}