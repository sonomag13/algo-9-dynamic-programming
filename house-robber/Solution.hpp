// LeetCode 198. House Robber

#include <vector>

using nanmespace std; 

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size(); 

        vector<int> money(n, 0);

        money[0] = nums[0];
        if (n > 1) {
            money[1] = max(money[0], nums[1]);
        }
        
        for (int i = 2; i < n; ++i) {
            // money[i - 2] + nums[i] -- do not rob house i - 1 and instead robbing i 
            // money[i - 1] -- do not rob house i and keep whatever in i - 1
            money[i] = max(money[i - 2] + nums[i], money[i - 1]); 
        } 

        return money.back();
    }
};