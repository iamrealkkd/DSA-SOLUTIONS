class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        // Store all elements
        for (int x : nums) {
            st.insert(x);
        }

        // Check multiples of k
        int multiple = k;

        while (st.count(multiple)) {
            multiple += k;
        }

        return multiple;
    }
};