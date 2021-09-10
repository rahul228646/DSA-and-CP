// O((logE + V)E) max val of E can be V
// after improvement
// O((logE + ElogV))
#include <iostream>
using namespace std;

class Edge{
public:
    int source;
    int destination;
    int weight;
};

int findParent(int V, int *parent){
    if(parent[V] == V)
        return V;
    return findParent(parent[V], parent);
}

bool sortByWeight(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

void kruskal(Edge *input, int V, int E){
    //sort by weight
    sort(input, input + E, sortByWeight);
    
    Edge *output = new Edge[V-1];
    
    int *parent = new int[V];
    for(int i = 0; i < V; i++){
        parent[i] = i;
    }
    
    int count = 0;
    int i = 0;
    
    while(count != V-1){
        Edge current = input[i];
        
        //check if it can be add i.e. it dosen't forms a cycle
        int sourceParent = findParent(current.source, parent);
        int destinationParent = findParent(current.destination, parent);
        
        if(sourceParent != destinationParent){
            output[count++] = current;
            parent[sourceParent] = destinationParent;
        }
        i++;
    }
    for(int i = 0; i<V-1; i++){
        if(output[i].source < output[i].destination){
            cout<<output[i].source<<" ";
            cout<<output[i].destination<<" ";
            cout<<output[i].weight<<" ";
            cout<<endl;
        }
        else{
            cout<<output[i].destination<<" ";
            cout<<output[i].source<<" ";
            cout<<output[i].weight<<" ";
            cout<<endl;
        }
    }
    
}

int main() {
    int V, E;
    cin>>V>>E;
    Edge *input = new Edge[E];
    
    for(int i = 0; i < E; i++){
        cin>>input[i].source>>input[i].destination>>input[i].weight;
    }
    kruskal(input, V, E);
    return 0;
}
