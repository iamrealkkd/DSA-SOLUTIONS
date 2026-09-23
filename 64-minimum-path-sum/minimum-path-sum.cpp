class Solution {
public:
    int findMinPathSum(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& t) {
        
        if(i == m-1 && j == n-1)
            return t[i][j] = grid[i][j];

        if(t[i][j] != -1)
            return t[i][j];

        if(i == m-1) { // only right
            return t[i][j] = grid[i][j] + 
                findMinPathSum(grid, i, j+1, m, n, t);
        }
        else if(j == n-1) { // only down
            return t[i][j] = grid[i][j] + 
                findMinPathSum(grid, i+1, j, m, n, t);
        }
        else {
            return t[i][j] = grid[i][j] + 
                min(
                    findMinPathSum(grid, i+1, j, m, n, t),
                    findMinPathSum(grid, i, j+1, m, n, t)
                );
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> t(m, vector<int>(n, -1));

        return findMinPathSum(grid, 0, 0, m, n, t);
    }
};