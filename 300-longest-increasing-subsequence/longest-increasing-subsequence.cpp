class Solution {
public:
    int findLength(vector<int>& nums, int i, int p, vector<vector<int>>& dp) {
        int n = nums.size();

        if (i >= n) {
            return 0;
        }

        if (p != -1 && dp[i][p] != -1) {
            return dp[i][p];
        }

        int take = 0;

        if (p == -1 || nums[i] > nums[p]) {
            take = 1 + findLength(nums, i + 1, i, dp);
        }

        int skip = findLength(nums, i + 1, p, dp);

        if (p != -1) {
            return dp[i][p] = max(take, skip);
        }

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return findLength(nums, 0, -1, dp);
    }
};
