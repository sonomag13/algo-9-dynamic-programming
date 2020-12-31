#include <vector>

using namespace std; 

class Solution {

public:
    int coinChange(vector<int>& coins, int amount) {
        
        int numCoins; 
        int inf{INT_MAX}; 

        /**
         * Index: amount, e.g. idx = 27 means amount = 27
         * Value: minimum number coins to obtain the amount as 
         *        specified by the index
         * 
         * Goal: if vectAmount[amount] has a finite value? 
         * Subtask: given the coin in coins, does vectAmount[N - coin] 
         * have a finite value? If not, we use inf as the value
         **/        
        vector<int> vectAmount(amount + 1, inf);
        
        // initial condition
        vectAmount[0] = 0; 
        
        // use top down approach
        for (int currAmount = 1; currAmount < vectAmount.size(); ++currAmount) {            
            /**
             * this vector to record all the candidate to get the current amount
             * from the previous amounts with the given coins
             **/
            vector<int> vectCandidate;             
            for (int coinIdx = 0; coinIdx < coins.size(); ++coinIdx) {
                int coinValue{coins[coinIdx]}; 
                int prevAmount{currAmount - coinValue};       
                /**
                 * 2 cases:
                 * - B.C.:the prevAmount cannot be nagative since it represent the index
                 * - vectAmount[prevAmount] should have a finite value such that 
                 *   vectAmount[currAmount] has a finite value
                 **/
                bool cond1{prevAmount >= 0};
                bool cond2{false}; 
                if (cond1) {
                    cond2 = vectAmount[prevAmount] != inf; 
                }                
                if (cond1 && cond2) {
                    vectCandidate.push_back(vectAmount[prevAmount] + 1);
                } 
                else {
                    vectCandidate.push_back(inf); 
                }
            }
            // the final value is the minimum of the previous amount
            vectAmount[currAmount] = *min_element(vectCandidate.begin(), vectCandidate.end());
        }                                
        
        /**
         * finally, if there is a solution, vectAmount[amount] should be finite; 
         * otherwise, the combination of the coins to get this amount does not exist
         **/ 
        return vectAmount[amount] == inf ? -1 : vectAmount[amount]; 

    }

};