// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adj;
        queue<int> q;
        vector<int> inDegree(n, 0);
        vector<int> r;

        int count = 0;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            // v --> u
            adj[v].push_back(u);
            inDegree[u]++;
        }

        // Pushing nodes with inDegree 0
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
                r.push_back(i);
                count++;
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto v : adj[u])
            {
                inDegree[v]--;
                if (inDegree[v] == 0)
                {
                    count++;
                    q.push(v);
                    r.push_back(v);
                }
            }
        }

        vector<int> temp;
        return (count == n) ? r : temp;
    }
};

// Helper to print the result
void printVector(const vector<int> &vec)
{
    if (vec.empty())
    {
        cout << "[] (Cycle detected)" << endl;
    }
    else
    {
        cout << "[ ";
        for (int num : vec)
            cout << num << " ";
        cout << "]" << endl;
    }
}
// class Solution {
// public:
//     bool DFS(unordered_map<int,vector<int>> &adj,int u,int n,vector<bool> &inRecursion,vector<bool> &visited,vector<int> &r){
//         visited[u] = true;
//         inRecursion[u]  = true;
//         for(auto v:adj[u]){
//             if(!visited[v] && DFS(adj,v,n,inRecursion,visited,r)){
//                 return true;
//             }else if(inRecursion[v]) return true;
//         }
//         inRecursion[u] = false;
//         r.push_back(u);
//         return false;
//     }
//     vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
//         unordered_map<int,vector<int>> adj;
//         vector<bool> visited(n,false);
//         vector<bool> inRecursion(n,false);
//         vector<int> r;
//         vector<int> temp;
//         bool flag = true;

//         for(int i=0;i<prerequisites.size();i++){
//             int u  = prerequisites[i][0];
//             int v  = prerequisites[i][1];

//             // v-->u
//             adj[v].push_back(u);
//         }

//         //Calling DFS
//         for(int i=0;i<n;i++){
//             if(!visited[i] && DFS(adj,i,n,inRecursion,visited,r)){
//               flag = false;
//               break;
//             }
//         }
//         reverse(r.begin(),r.end());
//         return  (flag)?r:temp;
//     }
// };

int main()
{
    Solution sol;

    // Example 1: No cycle
    int n1 = 4;
    vector<vector<int>> prerequisites1 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    cout << "Order of courses (example 1): ";
    printVector(sol.findOrder(n1, prerequisites1));

    // Example 2: Cycle
    int n2 = 2;
    vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    cout << "Order of courses (example 2): ";
    printVector(sol.findOrder(n2, prerequisites2));

    // Example 3: No prerequisites
    int n3 = 3;
    vector<vector<int>> prerequisites3 = {};
    cout << "Order of courses (example 3): ";
    printVector(sol.findOrder(n3, prerequisites3));

    return 0;
}
