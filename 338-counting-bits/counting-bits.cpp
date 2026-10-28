class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for (int i = 0; i <= n; i++) {
            int num = i;
            int count = 0;

            for (int i = 0; i < 32; i++) {
                if (num & (1 << i))
                    count++;
            }

            ans.push_back(count);
        }

        return ans;
    }
};