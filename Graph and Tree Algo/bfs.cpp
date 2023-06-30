//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== BFS / level-wise ======//
//====== Time Complexity: O(V+E)  =====//
//===== Space Complexity: O(V+E) =====//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int v, vector<int> adj[]){
    int vis[v]={0};
    queue<int> q;
    vis[0]=1;
    q.push(0);
    vector<int> sol;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        sol.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }
    return sol;
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

    vector<int> sol = bfs(n, adj);
    for(auto it:sol){
        cout<<it<<" ";
    }
/* sample input for graph:
5 5
0 1
0 2
1 3
2 4
3 4
representation:
0---1---3
|   |   |
|   4   |
2-------4



output: 0 1 2 3 4


*/    
    return 0;
}