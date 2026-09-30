class Solution {
public:

    int findPath(int i, int j, int m, int n,
                 vector<vector<int>>& matrix,
                 vector<vector<int>>& dp) {

        if(i < 0 || i >= m || j < 0 || j >= n)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int up = 0;
        int down = 0;
        int left = 0;
        int right = 0;

        if(i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
            up = findPath(i - 1, j, m, n, matrix, dp);

        if(i + 1 < m && matrix[i + 1][j] > matrix[i][j])
            down = findPath(i + 1, j, m, n, matrix, dp);

        if(j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
            left = findPath(i, j - 1, m, n, matrix, dp);

        if(j + 1 < n && matrix[i][j + 1] > matrix[i][j])
            right = findPath(i, j + 1, m, n, matrix, dp);

        return dp[i][j] = 1 + max({up, down, left, right});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, findPath(i, j, m, n, matrix, dp));
            }
        }

        return ans;
    }
};