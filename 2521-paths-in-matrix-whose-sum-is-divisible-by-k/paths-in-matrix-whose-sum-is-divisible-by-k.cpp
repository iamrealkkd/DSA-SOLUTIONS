class Solution {
public:
    const int MOD = 1e9 + 7;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m,
            vector<vector<int>>(n, vector<int>(k, 0))
        );

        
        for (int sum = 0; sum < k; sum++) {
            int newSum = (sum + grid[m - 1][n - 1]) % k;

            if (newSum == 0)
                dp[m - 1][n - 1][sum] = 1;
        }

      
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (i == m - 1 && j == n - 1)
                    continue;

                for (int sum = 0; sum < k; sum++) {

                    int newSum = (sum + grid[i][j]) % k;

                    int ans = 0;

                    if (i + 1 < m) {
                        ans += dp[i + 1][j][newSum];
                    }

                    if (j + 1 < n) {
                        ans += dp[i][j + 1][newSum];
                    }

                    dp[i][j][sum] = ans % MOD;
                }
            }
        }

        return dp[0][0][0];
    }
};