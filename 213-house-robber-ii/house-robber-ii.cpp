class Solution {
public:
    int solve(int i, int end, vector<int>& nums, vector<int>& dp) {

        if (i > end)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        return dp[i] = max(
            nums[i] + solve(i + 2, end, nums, dp),
            solve(i + 1, end, nums, dp)
        );
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        // Case 1: exclude last house
        vector<int> dp1(n + 2, -1);
        int case1 = solve(0, n - 2, nums, dp1);

        // Case 2: exclude first house
        vector<int> dp2(n + 2, -1);
        int case2 = solve(1, n - 1, nums, dp2);

        return max(case1, case2);
    }
};