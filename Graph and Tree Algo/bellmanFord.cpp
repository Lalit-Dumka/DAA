//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== Bellman Ford ======//
//====== Time Complexity : O() =====//
//===== Space Complexity : O() =====//

#include <iostream>
#include <vector>


using namespace std;

vector<int> bellmanFord(int v, vector<vector<int>> edges, int s){
    vector<int> dist(v,INT_MAX);
    dist[s]=0;

    for(int i=0; i<v-1; i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1]; 
            int w = it[2];
            if(dist[u]!=INT_MAX && dist[u]+w < dist[v])
                dist[v] = dist[u]+w;
        }
    }
    for( auto it: edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if(dist[u]!=INT_MAX && dist[u]+w < dist[v]){
            cout << "Negative weight cycle found" << endl;
            exit(0);
        }
    }
    return dist;
}

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<int>> edges;
    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<int> dist = bellmanFord(v, edges, 0);
    for(int i=0; i<v; i++)
        cout << dist[i] << " ";
    cout << endl;
    
    
    return 0;
}