//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== DFS ======//
//space complexity: O(V+E)
//time complexity: O(V+E)

#include <iostream>
#include <vector>

using namespace std;



void dfs(int node, vector<int> adj[], int vis[], vector<int> &sol){
    vis[node]=1;
    sol.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, sol);
        }
    }

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
    vector<int> sol;
    dfs(0, adj, vis, sol);
    for(auto it:sol){
        cout<<it<<" ";
    }

    return 0;
}

/*
sample input:
6 5
0 1
0 2
1 3
1 5
3 4

representation:
0---1---3
|   |   |
|   5   |
2       4

output: 0 1 3 4 5 2

*/