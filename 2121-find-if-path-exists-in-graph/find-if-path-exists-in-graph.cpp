class Solution {
public:

    void dfs(int node,
             unordered_map<int, vector<int>>& graph,
             vector<int>& visited) {

        visited[node] = 1;

        for (int nbr : graph[node]) {
            if (!visited[nbr]) {
                dfs(nbr, graph, visited);
            }
        }
    }

    bool validPath(int n,
                   vector<vector<int>>& edges,
                   int source,
                   int destination) {

        unordered_map<int, vector<int>> graph;

        for (auto &e : edges) {
            int a = e[0];
            int b = e[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> visited(n, 0);

        dfs(source, graph, visited);

        return visited[destination];
    }
};