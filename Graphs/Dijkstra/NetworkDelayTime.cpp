// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

// Example 1:


// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2
// Example 2:

// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1
// Example 3:

// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1
 

// Constraints:

// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Min-heap priority queue: {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // Adjacency list: node -> list of {neighbor, weight}
        vector<vector<pair<int,int>>> adj(n + 1);
        
        for (auto &i : times) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v, wt});
        }

        // Distance array initialized to INT_MAX
        vector<int> result(n + 1, INT_MAX);
        result[k] = 0; // Distance to source is 0

        pq.push({0, k});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (auto &v : adj[u]) {
                int node = v.first;
                int wt = v.second;

                if (d + wt < result[node]) {
                    result[node] = d + wt;
                    pq.push({d + wt, node});
                }
            }
        }

        // Ignore result[0] since nodes are 1-indexed
        int max_ele = *max_element(result.begin() + 1, result.end());

        return (max_ele == INT_MAX) ? -1 : max_ele;
    }
};

// Main function to test
int main() {
    Solution sol;

    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };
    int n = 4;
    int k = 2;

    int result = sol.networkDelayTime(times, n, k);
    cout << "Network Delay Time: " << result << endl;

    return 0;
}
