//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== BFS / level-wise ======//
//====== Time Complexity: O(V+E)  =====//
//===== Space Complexity: O(V+E) =====//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//using bfs
/*
bool detectCycle(int src, vector<int> adj[], int vis[]){
    
    queue<pair<int, int>> q;
    vis[src]=1;
    q.push({src,-1});

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it,node});
            }
            else if(parent != it){
                return true;
            }
        }
    }
    return false;
}
*/


//using dfs
// time complexity: O(V+E)
// space complexity: O(V+E) + O(V) + O(V) = O(V+E)
bool detectCycle(int node, int parent, vector<int> adj[], int vis[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!(vis[it])){
            if (detectCycle(it, node, adj, vis)) return true;
        }
        else if(parent != it){
            return true;
        }
    }
    return false;
}

bool detectCycleInAllComponents(int v, vector<int> adj[], int vis[]){
    for(int i=0; i<v; i++){
        if(!vis[i]){
            if(detectCycle(i,-1,adj,vis)==true) return true;
        }
    }
    return false;
}

int main(){
    
    int n, m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int vis[n]={0};
    // cout<<detectCycle(0,-1,adj,vis)<<endl;
    cout<<detectCycleInAllComponents(n,adj,vis)<<endl;
/* sample input for graph:
10 9
0 1
0 2
1 3
1 4
3 5
6 7
7 8 
8 9
7 9
representation:
0---1---3
|   |   |
|   4   |
2       5

6---7---8---9
    |_______|

output: 0 1 2 3 4


*/    
    return 0;
}