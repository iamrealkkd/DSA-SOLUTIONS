class Solution {
public:
    void generateSubsets(int index, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums) {

        ans.push_back(temp);

        for(int i = index; i < nums.size(); i++) {

            temp.push_back(nums[i]);

            generateSubsets(i + 1, temp, ans, nums);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        generateSubsets(0, temp, ans, nums);

        return ans;
    }
};