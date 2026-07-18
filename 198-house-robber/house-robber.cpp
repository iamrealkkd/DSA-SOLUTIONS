class Solution {
public:

    int solve(int i, vector<int>& nums, vector<int>&t) {

        // Base Case
        if (i >= nums.size())
            return 0;
        if (t[i] != -1)
            return t[i];
        // Choice 1: Rob current house
        // Choice 2: Skip current house
        return t[i] = max(
            nums[i] + solve(i + 2, nums, t),
            solve(i + 1, nums, t)
        );
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int>t(n, -1);

        // Start from House 0
        return solve(0, nums, t);
    }
};