class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int index, vector<int>& candidates, int target) {

        // Found a valid combination
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        // Invalid case
        if (index == candidates.size() || target < 0) {
            return;
        }

        // Take current element
        curr.push_back(candidates[index]);
        solve(index, candidates, target - candidates[index]); // same index
        curr.pop_back();

        // Don't take current element
        solve(index + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};