class Solution {
public:
    
    int myFunc(int n, vector<int> &dp)
    {
        if(n == 0)
        {
            return 1;
        }
        if(dp[n] != -1) return dp[n];
        int left = 0, right = 0;
        left = myFunc(n - 1, dp);
        if(n > 1)   right = myFunc(n - 2, dp);
        dp[n] = left + right;
        return dp[n];
    }
    
    int climbStairs(int n) {
        // if(n == 0)  return 1;
        // int left = 0, right = 0;
        // left = climbStairs(n - 1);
        // if(n > 1)   right = climbStairs(n - 2);
        // return left + right;
        
        vector<int> dp(n + 1, -1);
        int ans = myFunc(n, dp);
        return ans;
    }
};