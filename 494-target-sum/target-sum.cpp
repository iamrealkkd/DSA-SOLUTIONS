class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if ((target + totalSum) % 2 != 0 || totalSum < abs(target))
            return 0;

        int newTarget = (target + totalSum) / 2;

        int n = nums.size();
        vector<vector<int>> t(n + 1, vector<int>(newTarget + 1, 0));

        for (int i = 0; i <= n; i++)
            t[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= newTarget; j++) {
                if (nums[i - 1] <= j)
                    t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        return t[n][newTarget];
    }
};