class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int sum = 0;
        sort(nums.begin(), nums.end(), greater<int>());
            while(k){
                int f = nums[0];
                sum += f;
                nums[0] = f + 1;
                k--;
            }

            return sum;
    }
};