// LeetCode 518. Coin Change II

#include <vector>

using namespace std; 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        if (amount == 0) {
            // corner case: there is one way to make a change of amount 0, i.e. do not give any coin
            return 1;  
        }

        int numCoins = coins.size(); 
        vector<vector<int>> dp(numCoins + 1, vector<int>(amount + 1, 0));

        /**
         * dp[i][j] -- the ways to make change of j with [0, i] coins 
         * j: from 0 to amount
         * i: coins from 0 to i - 1; notice that we inserted a coin with zero value into the dp
         */
        for (int i = 0; i < numCoins + 1; ++i) {
            // to make amount 0, we need minimum 0 coin
            dp[i][0] = 0;  
        }

        for (int j = 1; j < amount + 1; ++j) {
            // there is zero way to make a non-zero j with coins with 0 coin
            dp[0][j] = 0; 
        }

        dp[0][0] = 1;  // there is one way to make 0 amount with 0 coin

        for (int curAmount = 1; curAmount <= amount; ++curAmount) {
            for (int coinIdx = 1; coinIdx <= numCoins; ++coinIdx) {
                int curCoin = coins[coinIdx - 1];

                if (curAmount - curCoin == 0) {
                    ++dp[coinIdx][curAmount];  // curAmount with curCoin is a solution
                }

                int preChange;
                if (curCoin > curAmount) {
                    // the current coin is larger than the current amout, no way to make a change
                    preChange = 0; 
                }
                else {
                    // it is possible to use the current coin to make a change, let us check 
                    // out curAmount - curCoin. 
                    // If there is no way to make change for amount of curAmount - curCoin, there 
                    // is no way to make change at curAmount since curCoin is what we have
                    preChange = dp[coinIdx][curAmount - curCoin];
                }

                // the final answer is sum of:
                // 1. previous way to change for the amount that does not include curCoin
                // 2. if dp[curCoin][curAmount] itself is a solution
                // 3. without the curent coint, if amount can be changed
                dp[coinIdx][curAmount] = preChange + dp[coinIdx][curAmount] + dp[coinIdx - 1][curAmount];
            }
        }
        
        return dp[numCoins][amount] == 0 ? 0 : dp[numCoins][amount];
    }
};