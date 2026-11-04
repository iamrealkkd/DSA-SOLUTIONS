class Solution {
public:
    bool isF(string s, int l, int r) {
        while(l < r){
            if(s[l] != s[r])return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n - 1;

        while(l < r) {
            if(s[l] != s[r]) return isF(s, l + 1, r) || isF(s, l, r - 1); 
            l++;
            r--;
        }
        return true;
    }
};