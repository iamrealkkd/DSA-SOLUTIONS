class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int pref, suff, best, len;
    };

    vector<Node> seg;
    string s;

    Node merge(Node left, Node right) {
        Node res;

        res.len = left.len + right.len;
        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;

        // Prefix
        res.pref = left.pref;
        if (left.pref == left.len &&
            left.rightChar == right.leftChar) {
            res.pref += right.pref;
        }

        // Suffix
        res.suff = right.suff;
        if (right.suff == right.len &&
            left.rightChar == right.leftChar) {
            res.suff += left.suff;
        }

        // Best answer
        res.best = max(left.best, right.best);

        // If same characters meet at boundary
        if (left.rightChar == right.leftChar) {
            res.best = max(res.best, left.suff + right.pref);
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            char c = s[l];
            seg[node] = {c, c, 1, 1, 1, 1};
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            seg[node] = {ch, ch, 1, 1, 1, 1};
            return;
        }

        int mid = l + (r - l) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, ch);
        else
            update(node * 2 + 1, mid + 1, r, idx, ch);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;

        int n = s.size();
        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};