// Kruskal's algorithm
// Time Complexity: O(E(log|V|))
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct edge_s{
    int src; int dest; int weight;
};


struct subset{
    int parent; int rank;
};

int find(subset subsets[], int i){
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(edge_s a, edge_s b){
    return a.weight < b.weight;
}

class Graph {
private:
    int V; int E;
    vector<edge_s> edge;
public:
    Graph(int V, int E){
        this->V = V;
        this->E = E;
    }

    void add_Edge(int src, int dest, int wt){
        edge_s p;
        p.src = src;
        p.dest = dest;
        p.weight = wt;
        edge.push_back(p);
    }

    void KruskalMST(){
        edge_s result[V];
        for (int j = 0; j < V; ++j) {
            result[j].src = 0;
            result[j].dest = 0;
            result[j].weight = INT_MAX;
        }
        sort(begin(edge),end(edge),myComp);
        auto *subsets = new subset[( V*sizeof(subset) )];
        for (int v = 0; v < V; ++v){
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }
        int e=0; int k=0;
        while(e<V-1 && k<E){
            auto next_edge = edge[k];
            k++;
            int x = find(subsets, next_edge.src);
            int y = find(subsets, next_edge.dest);
            if (x != y){
                result[e] = next_edge;
                Union(subsets, x, y);
                e++;
            }
            }
        for (int i = 0; i < V-1; ++i)
            if(result[i].src!=0)
                cout<<result[i].src<<" -- "<<result[i].dest<<" == "<<result[i].weight<<endl;
    }
};



int main() {

    int v; int e;
    int a; int b; int d;
    cin >> v >> e;
    Graph g(v + 1,e);
    for (int i = 1; i <= e; i++) {
        cin >> a >> b >> d;
        g.add_Edge(a, b, d);
    }
    g.KruskalMST();
    return 0;
}