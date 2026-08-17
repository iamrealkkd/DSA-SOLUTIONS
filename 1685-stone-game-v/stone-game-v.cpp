class Solution {
public:
    vector<vector<int>> dp;
    vector<int> prefix;

    int solve(int i, int j) {
        if (i >= j) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        for (int k = i; k < j; k++) {

            int leftSum = prefix[k + 1] - prefix[i];
            int rightSum = prefix[j + 1] - prefix[k + 1];

            if (leftSum < rightSum) {
                ans = max(ans, leftSum + solve(i, k));
            }
            else if (leftSum > rightSum) {
                ans = max(ans, rightSum + solve(k + 1, j));
            }
            else {
                ans = max(ans,
                    max(leftSum + solve(i, k),
                        rightSum + solve(k + 1, j))
                );
            }
        }

        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        prefix.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1);
    }
};