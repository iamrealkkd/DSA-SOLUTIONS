class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1 = 0;
        int maxi2 = 0;

        for (int x : nums) {
            if (x > maxi1) {
                maxi2 = maxi1;
                maxi1 = x;
            }
            else if (x > maxi2) {
                maxi2 = x;
            }
        }

        return (maxi1 - 1) * (maxi2 - 1);
    }
};