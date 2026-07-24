class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx = 0;

        for (int x : nums)
            mx = max(mx, x);

        int B = 1;
        while (B <= mx)
            B <<= 1;

        vector<bool> one(B, false);
        vector<bool> two(B, false);
        vector<bool> three(B, false);

        for (int x : nums)
            one[x] = true;

        for (int x = 0; x < B; x++) {
            if (!one[x]) continue;

            for (int y = 0; y < B; y++) {
                if (one[y])
                    two[x ^ y] = true;
            }
        }

        for (int x = 0; x < B; x++) {
            if (!two[x]) continue;

            for (int y = 0; y < B; y++) {
                if (one[y])
                    three[x ^ y] = true;
            }
        }

        int ans = 0;

        for (bool x : three)
            ans += x;

        return ans;
    }
};