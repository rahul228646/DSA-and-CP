it is used to get minimum spanning tree;
if we have V (nodes) number of vertices in the graph and then MST will have V-1 edges
time : O(ElogE + ElogV)
Space : O(V)

#include <bits/stdc++.h>

#define MAX 1010

using namespace std;

vector <pair<int, pair<int, int> > > edges;
int parent[MAX], _rank[MAX];

// union find by path compression
int find_set(int x){
    if(x == parent[x]) return x;
    parent[x] = find_set(parent[x]) // path compression step
    return parent[x];
}
// union join
// if(i == j) cycle is detected , it does not work for self loop
// rank compression
bool union_set(int x, int y){
    int i = find_set(x),
        j = find_set(y);

    if(i != j){
        if(_rank[i] > _rank[j]){
            parent[j] = i;
            _rank[i] += _rank[j];
        }else{
            parent[i] = j;
            _rank[j] += _rank[i];
        }

        return true;
    }
    return false;
}

int kruskal(int v, int e){
    int mst = 0, k = 0, w, x, y;
    
    sort(edges.begin(), edges.end()); // ElogE (dominant)

    for(int i = 0; i < e && k < v - 1; i++){ // can be ElogV (i<e) or VlogV (i<v-1)
        w = edges[i].first;
        x = edges[i].second.first, y = edges[i].second.second;

        if(union_set(x, y)){
            mst += w;
            k++;
        }
    }
    
    return mst;
}

int main(){

    int v, e, x, y, w;

    for(int i = 1; i <= v; i++){
        _rank[i] = 0;
        parent[i] = i;
    }

    while(e--){
        scanf("%d %d %d", &x, &y, &w);
        edges.push_back(make_pair(w, make_pair(x, y)));
    }

    kruskal(v, e);

    return 0;
}
