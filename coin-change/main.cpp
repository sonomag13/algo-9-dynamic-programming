/*
    669. Coin Change

    You are given coins of different denominations and a total amount of money amount. Write a function to compute the
    fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any
    combination of the coins, return -1.

    Example1

    Input:
    [1, 2, 5]
    11
    Output: 3
    Explanation: 11 = 5 + 5 + 1
    Example2

    Input:
    [2]
    3
    Output: -1

    You may assume that you have an infinite number of each kind of coin.
    It is guaranteed that the num of money will not exceed 10000.
    And the num of coins wii not exceed 500，The denomination of each coin will not exceed 100

 */

#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * @param coins: a list of integer
     * @param amount: a total amount of money amount
     * @return: the fewest number of coins that you need to make up
     */

    int coinChange(vector<int> &coins, int amount) {

        if (amount == 0 || coins.empty()) {
            return -1;
        }

        // define the maximum value and the array
        int inf = INT_MAX;

        // number of the coin types
        const int coin_num = coins.size();

        /**
         * initial condition where the first entry of the vector is 0
         * - index: the amount of each subtask, i.e. 0, 1, 2, ..., 27
         * - value: the number of the coins to get the amount
         */
        vector<int> vectorAmount(amount + 1, inf);
        vectorAmount[0] = 0;

        /**
         * transfer functiog using the classic case of coint = [2, 5, 7] and
         * amount = 27 for example:
         * f[x] = min{ f[x-2]+1, f[x-5]+1, f[x-7]+1 }
         */

        // traverse through the subtasks
        for (int currentAmount = 1; currentAmount < vectorAmount.size(); currentAmount++) {
            // traverse through the coin options
            vector<int> amountSubtask(coin_num, inf);
            for (int coin_idx = 0; coin_idx < coin_num; coin_idx++) {
                int preAmount = currentAmount - coins[coin_idx];
                /**
                 * apply the boundary condition here:
                 * 1. the previous amount must be larger than 0
                 * 2. the previous amount must exist
                 */
                if (preAmount >= 0 && vectorAmount[preAmount] != inf) {
                    amountSubtask[coin_idx] = vectorAmount[preAmount] + 1;
                }
            }
            // apply the transfer function
            vectorAmount[currentAmount] = *min_element(amountSubtask.begin(), amountSubtask.end());
        }

        if (vectorAmount[amount] == inf) {
            return -1;
        }
        else{
            return vectorAmount[amount];
        }

    }

    int coinChange2(vector<int> &coins, int amount) {
        // write your code here
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for(int i = 1; i<=amount; ++i) {
            for(int j = 0; j<coins.size(); ++j) {
                int v = i-coins[j];
                if(v >= 0 && dp[v] != -1) {
                    if(dp[i] == -1 || dp[v]+1<dp[i]) {
                        dp[i] = dp[v]+1;
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main() {
    Solution solution;
    vector<int> coins{9, 9};
    int amount{0};
    int result = solution.coinChange2(coins, amount);

    cout << "minimum # coins = " << result << endl;

}
