// Bellman-Ford algorithm
// Time Complexity : O(|V||E|)
// E at max  = n(n-1)/2 ; V = n; worst time = O(n^3)

#include <iostream>
#include <vector>
#define INT_MAX 2147483647
using namespace std;


struct edge_s{
    int src; int dest; int weight;
};

class Graph {
private:
    int V; int E;
    int* dist;
    int* visited;
    vector<edge_s> edge;

public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        dist = new int[V];
    }

    void add_edge(int src, int dest, int weight){
        edge_s p;
        p.src = src;
        p.dest = dest;
        p.weight = weight;
        edge.push_back(p);
    }

    bool isNegCycleBellmanFord(int src){
        for (int i = 0; i < V; ++i)
            dist[i] = INT_MAX;
        dist[src] = 0;

        for (int i = 0; i <= V-1; ++i) {
            for (int j=0;j<E;j++) {
                int u = edge[j].src;
                int v = edge[j].dest;
                int weight = edge[j].weight;
                if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
                    dist[v] = dist[u]+weight;
            }
        }
        for (int j=0;j<E;j++) {
            int u = edge[j].src;
            int v = edge[j].dest;
            int weight = edge[j].weight;
            if(dist[u]!=INT_MAX && dist[u]+weight<dist[v])
                return true;
        }
        return false;
    }

    bool isNegCycleDisconnected(){
        visited = new int[V];
        for (int i = 1; i <= V; ++i) {
            if(!visited[i]){
                if(isNegCycleBellmanFord(i))
                    return true;
            }
            for (int j = 1; j <= V; ++j) {
                if(dist[j]!=INT_MAX)
                    visited[j]=true;
            }
        }
        return false;
    }

};

int main() {

    int v; int e;
    int a; int b; int d;
    cin >> v >> e;
    Graph g(v + 1,e);
    for (int i = 1; i <= e; i++) {
        cin >> a >> b >> d;
        g.add_edge(a, b, d);
    }
    cout<<g.isNegCycleDisconnected();
    return 0;
}