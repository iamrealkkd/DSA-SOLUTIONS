class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Step 1: (value, index) pairs banao
        vector<pair<int,int>> v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }

        // Step 2: value ke hisaab se descending sort
        sort(v.begin(), v.end(), greater<pair<int,int>>());

        // Step 3: top k elements dusre array me
        vector<pair<int,int>> top;
        for (int i = 0; i < k; i++) {
            top.push_back(v[i]);
        }

        // Step 4: ab INDEX ke hisaab se ascending sort (original order wapas)
        sort(top.begin(), top.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        // Step 5: sirf values nikaalo
        vector<int> ans;
        for (auto &p : top) {
            ans.push_back(p.first);
        }

        return ans;
    }
};