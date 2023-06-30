//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
// Dijkstra's Algorithm 
// Single Source Shortest Path
// Time Complexity : O(ElogV)
// Space Complexity : O(V+E)
// dijkstra doesn't work for negative weight cycle because it will keep on updating the distance of the nodes in the cycle and will never stop.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(int v, vector<vector<int>> adj[], int s){
    // using priority queue to get the minimum distance node in O(1) time 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    vector<int> dist(v, INT_MAX);  // vector to store the distance of all the nodes from source node

    dist[s] = 0;    // distance of source node from itself is 0
    pq.push({0, s}); // {distance, node} 

    while(!pq.empty()){   // while pq is not empty
        int dis = pq.top().first;  // distance of node from source
        int node = pq.top().second; // node
        pq.pop();  // pop the top element

        for(auto it : adj[node]){  // for all the adjacent nodes of the current node
            int adjNode = it[0];    // adjacent node
            int adjDis = it[1];     // distance of adjacent node from current node

            if(dist[adjNode] > dis + adjDis){  // if distance of adjacent node is greater than distance of current node + distance of adjacent node from current node
                dist[adjNode] = dis + adjDis;
                pq.push({dist[adjNode], adjNode});
            }                
        }
    }
    return dist;
}

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj[v];
    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist = dijkstra(v, adj, 0);
    for(int i=0; i<v; i++)
        cout << dist[i] << " ";
    cout << endl;
/*
sample input:
9 14
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
2 8 2
8 6 6
2 3 7
2 5 4
6 5 2
3 5 14
3 4 9
5 4 10

sample output:
0 4 12 19 21 11 9 8 14

*/
    
    return 0;
}