class Solution {
public:
    void permute(int start, vector<vector<int>>& v, vector<int>& nums){
        if(start == nums.size()){
            v.push_back(nums);
               return;
        }
        unordered_set<int>mp;
        for(int i = start; i < nums.size(); i++){
            if(mp.find(nums[i]) == mp.end()){
                mp.insert(nums[i]);
                  swap(nums[start], nums[i]);
                  permute(start + 1, v, nums);
                  swap(nums[start], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        permute(0, v, nums);
        return v;
    }
};