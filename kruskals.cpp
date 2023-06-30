//~~~~~~~~~~~~~~~~~~~~~~~~Lalit-Dumka~~~~~~~~~~~~~~~~~~~~~~~~//
//====== Kruskal's  ======//
//====== Time Complexity : O() =====//
//===== Space Complexity : O() =====//

// Spanning Tree: is a tree which spans all the vertices of the graph without cycles
// Minimum Spanning Tree: the spanning tree with minimum weight 

// Kruskal's Algorithm is a greedy approach to find min spanning tree

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int find(int parent[], int i){ // find the parent of the vertex
    if(parent[i] < 0){ // if parent is negative then it is the parent of itself
        return i;
    }
    return find(parent, parent[i]); // else find the parent of the parent
}

void union_by_weight(int parent[], int x, int y){ // union by weight of the parent vertex 
    int px = find(parent, x); // find the parent of x
    int py = find(parent, y); // find the parent of y
    if(px != py){ // if parents are different
        if(parent[px] < parent[py]){ // if parent of x has less weight
            parent[px] += parent[py]; // add the weight of y to x
            parent[py] = px; // make x the parent of y
        }
        else{ // if parent of y has less weight
            parent[py] += parent[px]; // add the weight of x to y
            parent[px] = py; // make y the parent of x
        }
    }
} 

typedef vector<pair<int, pair<int,int>>> viii;  // weight-(source-destination)
// time complexity of kruskal is O(E logE) where E is the number of edges
viii kruskals(viii g, int v){ // g is the graph and v is the number of vertices
    viii res;

    int parent[v];
    for(int i=0; i<v; i++){ // initialize parent array
        parent[i] = -1;
    }

    sort(g.begin(), g.end()); // sort the edges in increasing order of weight

    for (int i=0; i< g.size(); i++){ // for each edge
        int x = g[i].second.first; // source
        int y = g[i].second.second; // destination
        if(find(parent, x)!=find(parent,y)){ // if parents are different then there is no cycle
            res.push_back(g[i]); // add the edge to the result
            union_by_weight(parent, x, y); // union the two vertices

        }
    }
    return res;
}

int main(){
    viii g, res;
    int v, e, s, d, w;
    cin>>v>>e;
    for(int i=0; i<e; i++){
        cin>>s>>d>>w;
        g.push_back(make_pair(w, make_pair(s,d)));
    }
    res = kruskals(g,v);
    int sum = 0;
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i].second.first<<" "<<res[i].second.second<<" "<<res[i].first<<endl;
        sum += res[i].first;
    }
    cout<<"Total Weight: "<<sum<<endl; // total weight of the minimum spanning tree
/* 
example graph:
REPRESENTATION:
0-------1
| \   / |
|   2   |
| /   \ |
4-------3
INPUT:
5 6
0 1 2
0 2 3
0 4 5
1 2 1
2 3 2
3 4 3
OUTPUT:
1 2 1
0 1 2
2 3 2
3 4 3
Total Weight: 8
    


*/
    return 0;
}