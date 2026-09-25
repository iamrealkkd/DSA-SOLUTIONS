class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        // Last row copy
        for(int j = 0; j < n; j++) {
            dp[m - 1][j] = grid[m - 1][j];
        }

        // Bottom to top
        for(int i = m - 2; i >= 0; i--) {

            for(int j = 0; j < n; j++) {

                int path1 = INT_MAX;
                int path2 = INT_MAX;
                int path3 = INT_MAX;

                if(j - 1 >= 0)
                    path1 = dp[i + 1][j - 1];

                path2 = dp[i + 1][j];

                if(j + 1 < n)
                    path3 = dp[i + 1][j + 1];

                dp[i][j] = grid[i][j] + min({
                    path1,
                    path2,
                    path3
                });
            }
        }

        int ans = INT_MAX;

        for(int j = 0; j < n; j++) {
            ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};