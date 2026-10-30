class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int p = 1 << n;

        vector<vector<int>> ans;

        for(int mask = 0; mask < p; mask++) {
            vector<int> s;

            for(int bit = 0; bit < n; bit++) {
                if(mask & (1 << bit)) {
                    s.push_back(nums[bit]);
                }
            }

            ans.push_back(s);
        }

        return ans;
    }
};