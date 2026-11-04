class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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

            sort(s.begin(), s.end());
            ans.push_back(s);
        }

        set<vector<int>> st;

        for(auto subset : ans) {
            st.insert(subset);
        }

        vector<vector<int>> result(st.begin(), st.end());

        return result;
    }
};