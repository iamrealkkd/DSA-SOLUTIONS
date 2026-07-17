class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        // DP array
        // dp[i] = Minimum cost to reach the top starting from stair i
        vector<int> dp(n + 2, 0);

        // Fill DP table from back to front
        for (int i = n - 1; i >= 0; i--) {

            dp[i] = cost[i] + min(
                dp[i + 1],
                dp[i + 2]
            );
        }

        // We can start from stair 0 or stair 1
        return min(dp[0], dp[1]);
    }
};