//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== floyd Warshall ======//
//====== Time Complexity : O() =====//
//===== Space Complexity : O() =====//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>> graph){
    int v = graph.size();
    vector<vector<int>> dist(v, vector<int>(v, INT_MAX));

    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(i==j)
                dist[i][j]=0;
            else if(graph[i][j]!=0) // if there is a edge between i and j
                dist[i][j]=graph[i][j];
        }
    }

    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
    return dist;
}

int main(){
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v, vector<int>(v, 0));
    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v]=w;
    }

    vector<vector<int>> dist = floydWarshall(graph);
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            if(dist[i][j]==INT_MAX)
                cout << "NR" << " ";
            else
                cout << dist[i][j] << "  ";
        }
        cout << endl;
    }

/*
input:
4 5
0 1 5
0 3 10
1 2 3
2 3 1
3 2 4

output:
0  5  8  9
NR 0  3  4
NR NR 0  1
NR NR 4  0


*/
    
    
    return 0;
}