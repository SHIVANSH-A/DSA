// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        queue<int> q;
        vector<int> inDegree(n,0);
        int count = 0;

        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            // v --> u
            adj[v].push_back(u);
            inDegree[u]++;
        }

        // Push nodes with in-degree 0
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                count++;
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(auto v : adj[u]) {
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    count++;
                    q.push(v);
                }
            }
        }

        return (count == n);
    }
};
// class Solution {
// public:
//     bool DFS(unordered_map<int,vector<int>> &adj,int u,int n,vector<bool> &inRecursion,vector<bool> &visited){
//         visited[u] = true;
//         inRecursion[u]  = true;
//         for(auto v:adj[u]){
//             if(!visited[v] && DFS(adj,v,n,inRecursion,visited)){
//                 return true;
//             }else if(inRecursion[v]) return true;
//         }
//         inRecursion[u] = false;
//         return false;
//     }
//     bool canFinish(int n, vector<vector<int>>& prerequisites) {
//         unordered_map<int,vector<int>> adj;
//         vector<bool> visited(n,false);
//         vector<bool> inRecursion(n,false);


//         for(int i=0;i<prerequisites.size();i++){
//             int u  = prerequisites[i][0];
//             int v  = prerequisites[i][1];

//             // v-->u
//             adj[v].push_back(u);
//         }

//         //Calling DFS
//         for(int i=0;i<n;i++){
//             if(!visited[i] && DFS(adj,i,n,inRecursion,visited)){
//               return false;
//             }
//         }
//         return  true;
//     }
// };

int main() {
    Solution sol;

    // Example 1
    int n1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Can finish all courses (example 1)? " << (sol.canFinish(n1, prerequisites1) ? "Yes" : "No") << endl;

    // Example 2 (cycle)
    int n2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Can finish all courses (example 2)? " << (sol.canFinish(n2, prerequisites2) ? "Yes" : "No") << endl;

    // Example 3 (more complex)
    int n3 = 4;
    vector<vector<int>> prerequisites3 = {{1, 0}, {2, 1}, {3, 2}};
    cout << "Can finish all courses (example 3)? " << (sol.canFinish(n3, prerequisites3) ? "Yes" : "No") << endl;

    return 0;
}
