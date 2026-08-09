class Solution {
public:

    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int solve(int i, int M) {

        if (i >= n)
            return 0;

        if (i + 2 * M >= n)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for (int X = 1; X <= 2 * M; X++) {

            int opponent = solve(i + X, max(M, X));

            int current = suffix[i] - opponent;

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        suffix.resize(n);

        suffix[n - 1] = piles[n - 1];

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = piles[i] + suffix[i + 1];

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};