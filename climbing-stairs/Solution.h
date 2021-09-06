class Solution {
public:
    int climbStairs(int n) {
        
        // DP
        // - i.c.: dp[1] = 1 as there is only one way to get to step 1
        //         dp[2] = 2 as there is only one way to get to step 2, 
        //         either going up with two 1 steps (i.e. 1 + 1) or going
        //         up with one 2 step                
        // - t.f.: dp[i] = dp[i - 1] + dp[i - 2]. In order to climb to
        //         step i, we can either climbing from i - 1 with 1 step, 
        //         or climbing from i - 2 with 2 steps
        
        if (n == 1 || n == 2) {
                return n; 
        }
        
        /* 
        // use vector as a memo
        vector<int> dp(n + 1, 0); 
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < dp.size(); ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
        */
        
        int pre1 = 1; 
        int pre2 = 2; 
        
        for (int i = 3; i <= n; ++i) {
            int curr = pre1 + pre2;
            pre1 = pre2;
            pre2 = curr;            
        }
        
        return pre2; 
    }
};