// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int n;
        // void DFS(int u,vector<vector<int>>& isConnected,vector<bool> &visited){
        //     if(visited[u]) return;
        //     visited[u] = true;
        //     for(int v=0;v<n;v++){
        //         if(!visited[v] && isConnected[u][v]==1) DFS(v,isConnected,visited);
        //     }
    
        //     return;
        // }
    
        void BFS(int u,vector<vector<int>>& isConnected,vector<bool> &visited){
            queue<int> q;
            q.push(u);
            visited[u] = true;
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                for(int v=0;v<n;v++){
                    if(!visited[v] && isConnected[temp][v]==1){
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
            return;
        }
    
        int findCircleNum(vector<vector<int>>& isConnected) {
            n = isConnected.size();
            vector<bool> visited(n,false);
    
            // unordered_map<int,vector<int>> adj;
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<n;j++){
            //         if(isConnected[i][j]==1){
            //              adj[i].push_back(j);
            //         }
            //     }
            // }
            int count = 0;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                    BFS(i,isConnected,visited);
                    count++;
                }
            }
            
            return count;
        }
    };

    int main() {
        Solution sol;
    
        // Example input: 3 nodes, 2 connected components
        vector<vector<int>> isConnected = {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 1}
        };
    
        int result = sol.findCircleNum(isConnected);
        cout << "Number of Provinces: " << result << endl;
    
        return 0;
    }    