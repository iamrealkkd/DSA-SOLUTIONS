class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int nextRow_1 = 0;
        int nextRow_0 = INT_MIN;

        for(int i = n - 1; i >= 0; --i) {
            int idealRow_1 = INT_MIN;
            int idealRow_0 = INT_MIN;

            for(int prevPick = 1; prevPick >= 0; --prevPick) {
                if(prevPick) {
                    int pickInSubarr = nextRow_1 + nums[i];
                    int stopHere = 0;

                    idealRow_1 = max(pickInSubarr, stopHere);
                }
                else {
                    int startNewFromCurr = nextRow_1 + nums[i];
                    int startNewFromNext = nextRow_0;

                    idealRow_0 = max(startNewFromCurr, startNewFromNext);
                }
            }

            swap(nextRow_1, idealRow_1);
            swap(nextRow_0, idealRow_0);
        }

        return nextRow_0;
    }
};