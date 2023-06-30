//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== Single Source Shortest Path for a DAG ======//
//====== Time Complexity : O() =====//
//===== Space Complexity : O() =====//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topoSort(int node, vector<pair<int,int>> adj[], int vis[], stack<int> &st[]){
    vis[node]=1;
    for( auto it: adj[node]){
        int v=it.first;
    }

}

vector<int> shortestPath(int n, vector<pair<int,int> adj[]){
    int vis[n]={0};
    stack<int> st;

    for(int i=0; i<n; i++){
        if(!vis[i]){

        }
    }
}

int main(){
    
    
    
    return 0;
}