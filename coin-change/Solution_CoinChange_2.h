#include <vector>

using namespace std; 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int inf = INT_MAX; 
        int numCoins = coins.size(); 
        vector<vector<int>> dp(numCoins + 1, vector<int>(amount + 1, 0));

        /**
         * dp[i][j] -- the min change to get j with coins [0, i - 1]
         * j: amount
         * i: coins from 0 to i - 1; notice that we inserted a coin with zero value into the dp
         */

        // boundary condition -- left column
        for (int i = 0; i < numCoins + 1; ++i) {
            // to make amount 0, we need minimum 0 coin
            dp[i][0] = 0;  
        }

        // boundary condition -- top row
        for (int j = 1; j < amount + 1; ++j) {
            // it takes inf coins with value zero to make a non-zero j; remember, j start from 1
            dp[0][j] = inf; 
        }

        for (int j = 1; j < amount + 1; ++j) {
            for (int i = 1; i < numCoins + 1; ++i) {
                
                int curCoin = coins[i - 1]; // get the current coin

                /**
                 * check if the current coint can be used for change, which depend on 
                 * if j - curCoin can be changed
                 */
                int preChange;
                if (curCoin > j) {
                    // The current coin is larger than the current amout, and
                    // there is no way to make a change
                    preChange = inf; 
                }
                else {
                    // It is possible to use the current coin to make a change, let us check 
                    // out j - curCoin.
                    //  
                    // If there is no way to make change for amount of j - curCoin, there is no way 
                    // to make change at j since curCoin is what we have
                    preChange = dp[i][j - curCoin];
                }

                // if we can make change for the amount of j - curCoin, we can make change with 
                // curCoin for amount j
                int curChange = preChange == inf ? inf : 1 + preChange; 
                
                // even though we can make change with curCoin, it does not mean that we must use 
                // curCoin. There might be other coins that can make change with less coins. 
                // 
                // For amount j, the amount of previous change is dp[i - 1][j] 
                dp[i][j] = min(curChange, dp[i - 1][j]);
            }
        }
        
        return dp[numCoins][amount] == inf ? -1 : dp[numCoins][amount];
    }
};