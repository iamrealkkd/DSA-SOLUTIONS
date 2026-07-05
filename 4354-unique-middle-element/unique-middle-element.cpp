class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int cnt = 0;
        for(int x : nums){
            cnt += (x == nums[nums.size()/2]);
        }
        return cnt == 1;
    }
};