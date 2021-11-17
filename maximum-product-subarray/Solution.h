// LeetCode 152. Maximum Product Subarray
// Medium

#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        const int n = nums.size(); 
        
        // boundary condition
        vector<int> dpMax(n);
        dpMax[0] = nums[0];
        
        vector<int> dpMin(n);
        dpMin[0] = nums[0];
        
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            
            /**
             * transfer function:
             * dpMax[i] = max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i], nums[i])
             * dpMin[i] = min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i], nums[i])
             *
             * dpMax[i] takes one of the following items
             *      dpMax[i - 1] * nums[i]: both dpMax[i - 1] and nums[i] are positive, e.g. +10 and +5
             *      dpMin[i - 1] * nums[i]: both dpMax[i - 1] and nums[i] are negative, e.g. -10 and -5
             *      nums[i]: dpMax[i - 1] and nums[i] have different signs, e.g. -10 and +1000 
             **/
            
            int prod1 = dpMax[i - 1] * nums[i];
            int prod2 = dpMin[i - 1] * nums[i];
            
            dpMax[i] = max(max(prod1, prod2), nums[i]);
            dpMin[i] = min(min(prod1, prod2), nums[i]);
            
            result = max(result, dpMax[i]);
            
        }        
        
        return result;  
        
        // or return *max_element(dpMax.begin(), dpMax.end());;  
        
    }
};