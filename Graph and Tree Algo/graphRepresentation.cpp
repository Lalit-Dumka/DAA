//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//======  ======//
//====== Time Complexity : O() =====//
//===== Space Complexity : O() =====//

#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    // adjacency matrix way for undirected graph
    // extra space: O(n^2)
    /*
    int n, m;
    cin>>n>>m;

    int adj[n+1][n+1];

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1; // change the value to edge weight if graph is weighted
        adj[v][u]=1; // change the value to edge weight if graph is weighted
    }
    */

    // adjacency list way for undirected graph
    // extra space: O(2*m)
    /*
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    */

    // adjacency list way for directed graph
    // extra space: O(m)
    /*
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    */


    // adjacency list way for weighted graph
    // extra space: O(2*m)
    
    int n, m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    for(int i=0; i<m; i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        adj[u].push_back(pair(v,weight));
        adj[v].push_back(pair(u,weight)); 
    }

    return 0;
}