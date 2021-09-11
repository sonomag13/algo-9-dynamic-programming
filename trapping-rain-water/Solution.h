// LeetCode 42. Trapping Rain Water
// Hard

#include <vector>

using namespace std; 

class Solution {
public:
    int trap(vector<int>& height) {
        
        // This is a memo rather than a DP
        
        // at a given position i, the water trapped is         
        // min( max(height[0, i - 1], max(height[i + 1, n]) ) - height[i]
        
        // To avoid searching on both for the max height for every i, 
        // let us build a memo~!
        
        const int n = height.size(); 
        
        vector<int> maxOnLeft(n, 0);
        vector<int> maxOnRight(n, 0);
        
        maxOnLeft[0] = height[0];
        for (int i = 1; i < n; ++i) {
            maxOnLeft[i] = max(maxOnLeft[i - 1], height[i]);
        }
        
        maxOnRight[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxOnRight[i] = max(maxOnRight[i + 1], height[i]);
        }
        
        int result = 0; 
        for (int i = 0; i < n; ++i) {
            result += min(maxOnLeft[i], maxOnRight[i]) - height[i]; 
        }
        
        return result; 
        
    }
};