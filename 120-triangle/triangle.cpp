class Solution {
public:
    int findMinPath(int i, int j, int m, int n, vector<vector<int>>& tri, vector<vector<int>>& t) {

        if(i < 0 || i >= m || j < 0 || j > i)
            return INT_MAX;

        if(i == m - 1)
            return tri[i][j];

        if(t[i][j] != INT_MAX)return t[i][j];

        return t[i][j] = tri[i][j] + min(
            findMinPath(i + 1, j, m, n, tri, t),
            findMinPath(i + 1, j + 1, m, n, tri, t)
        );
    }

    int minimumTotal(vector<vector<int>>& tri) {

        int m = tri.size();
        int n = tri[0].size();
        vector<vector<int>>t(m, vector<int>(m, INT_MAX));

        return findMinPath(0, 0, m, n, tri, t);
    }
};

