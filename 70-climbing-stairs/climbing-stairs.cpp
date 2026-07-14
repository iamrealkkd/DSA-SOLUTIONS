class Solution {
public:
    
    int solve(int n, vector<int>& dp) {

        // Base Cases
        if (n == 0)
            return 1;

        if (n == 1)
            return 1;

        // If already computed, return the stored answer.
        if (dp[n] != -1)
            return dp[n];

        // Compute and store the answer.
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);

        return dp[n];
    }

    int climbStairs(int n) {

        // dp[i] stores the number of ways to reach stair i.
        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};