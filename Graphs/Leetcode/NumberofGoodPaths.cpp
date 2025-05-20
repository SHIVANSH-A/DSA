// There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

// You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

// A good path is a simple path that satisfies the following conditions:

// The starting node and the ending node have the same value.
// All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
// Return the number of distinct good paths.

// Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.

 

// Example 1:


// Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
// Output: 6
// Explanation: There are 5 good paths consisting of a single node.
// There is 1 additional good path: 1 -> 0 -> 2 -> 4.
// (The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
// Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].



// Brute force  - Take max val nodes and take NC2 then remove them from graph
// Optimal - DSU Take min val nodes,construct union then check which belong to same component then calculate NC2
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int a, int b) {
        int parent_a = find(a);
        int parent_b = find(b);
        if (parent_a == parent_b) return;

        if (rank[parent_a] > rank[parent_b]) {
            parent[parent_b] = parent_a;
        } else if (rank[parent_a] < rank[parent_b]) {
            parent[parent_a] = parent_b;
        } else {
            parent[parent_a] = parent_b;
            rank[parent_b]++;
        }
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int V = vals.size();
        parent.resize(V);
        rank.resize(V, 0);
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < V; ++i)
            parent[i] = i;

        for (auto& i : edges) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        map<int, vector<int>> values_to_node;
        for (int i = 0; i < V; i++) {
            values_to_node[vals[i]].push_back(i);
        }

        vector<bool> active(V, false);
        int res = V; // each node alone is a good path

        for (auto i : values_to_node) {//Traversing on vals form min to max
            for (auto u : i.second) {//For a val connecting graph and marking them as active
                for (auto v : adj[u]) {
                    if (active[v]) Union(u, v);
                }
                active[u] = true;
            }

            vector<int> parents;
            for (auto u : i.second) {// For a val finding parent of each node
                int p = find(u);
                parents.push_back(p);
            }

            sort(parents.begin(), parents.end());
            for (int j = 0; j < parents.size(); j++) {//How many have same parent as they belong to same component
                long long count = 0;
                int curr_parent = parents[j];

                while (j < parents.size() && parents[j] == curr_parent) {
                    count++;
                    j++;
                }
                j--;
                int formula = (count * (count - 1) / 2); // NC2
                res += formula;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> vals = {1, 3, 2, 1, 3};
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {2, 3},
        {2, 4}
    };

    int result = sol.numberOfGoodPaths(vals, edges);
    cout << "Number of Good Paths: " << result << endl;

    return 0;
}

