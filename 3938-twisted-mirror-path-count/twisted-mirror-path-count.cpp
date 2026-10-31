
class Solution {
public:
    static const int MOD = 1'000'000'007;
    vector<vector<vector<int>>> dp;

    int solve(int row, int col, int direction, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (row >= m || col >= n) {
            return 0;
        }

        if (row == m - 1 && col == n - 1) {
            return 1;
        }

        int& answer = dp[row][col][direction];

        if (answer != -1) {
            return answer;
        }

        if (grid[row][col] == 1) {
            if (direction == 0) {
                answer = solve(row + 1, col, 1, grid);
            } else {
                answer = solve(row, col + 1, 0, grid);
            }
        } else {
            int right = solve(row, col + 1, 0, grid);
            int down = solve(row + 1, col, 1, grid);

            answer = (right + down) % MOD;
        }

        return answer;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));

        return solve(0, 0, 0, grid);
    }
};
