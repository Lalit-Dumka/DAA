//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== topological sort ======//
// time complexity: O(V+E)
// space complexity: O(V+E) + O(V) + O(V) = O(V+E)
// topological sort is only possible in directed acyclic graph (DAG)

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<int> adj[], int vis[], stack<int> &st){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!(vis[it])){
            dfs(it, adj, vis, st);

        }
    }
    st.push(node);
}


vector<int> topologicalSort(int v, vector<int> adj[]){
    int vis[v]={0};
    stack<int> st;
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    
    int n, m;
    cin>>n>>m;
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int> sol = topologicalSort(n, adj);
    for(auto it:sol){
        cout<<it<<" ";
    }
/* sample input for topological sort:
6 6
5 2
5 0
4 0
4 1
2 3
3 1
representation:
0---4---1
|   |   |
|   5   |
2---3---

output:
4 5 0 2 3 1


*/
    
    return 0;
}