// # There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.

// # You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.

// # Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.

// # Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.

// # Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

 

// # Example 1:

// # Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2

// # Output: [9,7,9,8,8]

// # Explanation:

// # For i = 0, connect node 0 from the first tree to node 0 from the second tree.
// # For i = 1, connect node 1 from the first tree to node 0 from the second tree.
// # For i = 2, connect node 2 from the first tree to node 4 from the second tree.
// # For i = 3, connect node 3 from the first tree to node 4 from the second tree.
// # For i = 4, connect node 4 from the first tree to node 4 from the second tree.

// # Example 2:

// # Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1

// # Output: [6,3,3,3,3]

// # Explanation:

// # For every i, connect node i of the first tree with any node of the second tree.


 

// # Constraints:

// # 2 <= n, m <= 1000
// # edges1.length == n - 1
// # edges2.length == m - 1
// # edges1[i].length == edges2[i].length == 2
// # edges1[i] = [ai, bi]
// # 0 <= ai, bi < n
// # edges2[i] = [ui, vi]
// # 0 <= ui, vi < m
// # The input is generated such that edges1 and edges2 represent valid trees.
// # 0 <= k <= 1000
// # Traverse the tree1 and find the count of edges which are at <=k
// # Then precompute count of the edges in tree2 for which edges are at <=k-1 (as one edge will be connected from tree1) then take node with max count of edges at <=k-1 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int BFS(unordered_map<int, vector<int>> &adj, int curr, int n, int d) {
        queue<pair<int, int>> q;
        q.push({curr, 0});
        vector<bool> visited(n, false);
        visited[curr] = true;

        int count = 0;
        while (!q.empty()) {
            int node = q.front().first;
            int val = q.front().second;
            q.pop();

            if (val > d) continue;
            count++;

            for (int v : adj[node]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, val + 1});
                }
            }
        }
        return count;
    }

    vector<int> find(vector<vector<int>>& edges, int d) {
        int n = edges.size() + 1;
        unordered_map<int, vector<int>> adj;

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> r(n);
        for (int i = 0; i < n; i++) {
            r[i] = BFS(adj, i, n, d);
        }

        return r;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        vector<int> r1 = find(edges1, k);
        vector<int> r2 = find(edges2, k - 1);

        int maxCount = *max_element(r2.begin(), r2.end());

        for (int i = 0; i < n; i++) {
            r1[i] += maxCount;
        }

        return r1;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<vector<int>> edges1 = {
        {0, 1}, {1, 2}, {1, 3}
    };
    vector<vector<int>> edges2 = {
        {0, 1}, {1, 2}
    };
    int k = 1;

    vector<int> result = sol.maxTargetNodes(edges1, edges2, k);

    cout << "Result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
