class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < n; right++) {

            // Add current character
            if (s[right] == '1') {
                ones++;
            }

            // Too many ones -> move left
            while (ones > k) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }

            // Remove unnecessary zeroes
            while (ones == k && s[left] == '0') {
                left++;
            }

            // We have a beautiful substring
            if (ones == k) {
                string curr = s.substr(left, right - left + 1);

                // Better length
                if (ans == "" || curr.size() < ans.size()) {
                    ans = curr;
                }

                // Same length -> lexicographically smaller
                else if (curr.size() == ans.size() && curr < ans) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};