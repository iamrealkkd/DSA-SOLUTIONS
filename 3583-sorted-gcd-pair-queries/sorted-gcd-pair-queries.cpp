class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<long long> gcdCnt(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {

            long long cnt = 0;

            for (int m = g; m <= mx; m += g)
                cnt += freq[m];

            gcdCnt[g] = cnt * (cnt - 1) / 2;

            for (int m = 2 * g; m <= mx; m += g)
                gcdCnt[g] -= gcdCnt[m];
        }

        vector<long long> pref(mx + 1, 0);

        for (int g = 1; g <= mx; g++)
            pref[g] = pref[g - 1] + gcdCnt[g];

        vector<int> ans;

        for (long long q : queries) {

            int g = lower_bound(pref.begin() + 1, pref.end(), q + 1) - pref.begin();

            ans.push_back(g);
        }

        return ans;
    }
};