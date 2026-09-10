class Solution {
public:
    void rec(int l, int r, int n, string s, vector<string>& ans){
        if(l > n || r > n) return ;
        if(l == n && r == n){
            ans.push_back(s);
            return;
        }
        rec(l+1, r, n, s + "(", ans);
        if(l > r){ // because valid parenthesis never starts with ")"
            rec(l, r+1, n, s + ")", ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        // string s = "";
        vector<string> ans;
        rec(0, 0, n, "", ans);
        return ans;
    }
};