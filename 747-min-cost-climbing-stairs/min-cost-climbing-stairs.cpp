class Solution {
public:
    int solve(int i, vector<int>& cost, vector<int>& dp) {

        // Base case: top reached or crossed.
        if (i >= cost.size()) {
            return 0;
        }

        // Memoization check.
        if (dp[i] != -1) {
            return dp[i];
        }

        // Store the answer before returning.
        dp[i] = cost[i] + min(
            solve(i + 1, cost, dp),
            solve(i + 2, cost, dp)
        );

        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {

        vector<int> dp(cost.size(), -1);

        return min(
            solve(0, cost, dp),
            solve(1, cost, dp)
        );
    }
};