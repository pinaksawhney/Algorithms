// representation of undirected graph as adjacency list

#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adjL[], int u, int v){

    adjL[u].push_back(v);
    adjL[v].push_back(u);
}

void printGraph(vector<int> adjL[], int V){
    for(int v=0;v<V;v++){
        cout<<"vertex "<<v<<" nodes";
        for(auto i: adjL[v]){
            cout<<"-> "<<i;
        }
        cout<<"\n";
    }
}

int main() {

    vector<int> adjL[5];
    addEdge(adjL,0,1);
    addEdge(adjL,0,4);
    addEdge(adjL, 1, 2);
    addEdge(adjL, 1, 3);
    addEdge(adjL, 1, 4);
    addEdge(adjL, 2, 3);
    addEdge(adjL, 3, 4);
    printGraph(adjL,5);

    return 0;
}
