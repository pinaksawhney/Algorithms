// TBD : Implement priority q in the form of heap for minDistance and update
// Time Complexity : O((V+E)logV)

#include <iostream>
#include <list>
#include <queue>
using namespace std;

// arbitrarily chosen - change edge weights as per the values
int edge_weights[6][6] = {{0, 0, 0, 0, 0, 0},
            {4, 0, 8, 0, 0, 0},
            {0, 8, 0, 7, 0, 4},
            {0, 0, 7, 0, 9, 14},
            {0, 0, 0, 9, 0, 10},
            {0, 0, 4, 14, 10,0}
        };

class Graph {
private:
    int V;
    list<int> *adj;
    int* dist;
    bool* sptset;
    int* parent;
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        dist = new int[V];
        sptset = new bool[V];
        parent = new int[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    int minDistance(){
        int min = INT_MAX; int min_indx = INT_MAX;
        for(int i=0;i<V;i++) {
            if (!sptset[i] && dist[i] <= min) {
                min = dist[i];
                min_indx = i;
            }
        }
        return min_indx;
    }
    // prints minDistance to all the nodes from the source
    void printSolution(int n){
        for (int i = 1; i < V; i++)
            cout<<i<<" "<<dist[i]<<endl;
    }
    // path prints shortest path from node to the source
    void printPath(int n){
        int i = n;
        cout<<n<<" ";
        while(parent[i] != -1){
            cout<<parent[i]<<" ";
            i = parent[i];
        }
    }

    void dijkstra(int src){
        for (int i = 0; i < V; i++) {
            dist[i] = INT_MAX;
            sptset[i] = false;
            parent[i]  =-1;
        }
        dist[src] = 0;
        for(int count=0;count<V-1;count++){
            int u = minDistance();
            sptset[u] = true;
            // 1 can be any random distance -- handle this TBD
            for (auto i = adj[u].begin(); i !=adj[u].end() ; ++i) {
                if(!sptset[*i] && dist[u]+edge_weights[u][*i]<dist[*i] && dist[u]!=INT_MAX) {
                    dist[*i] = dist[u] + edge_weights[u][*i];
                    parent[*i] = u;
                }
            }
        }
        printSolution(src);
    }
};

int main() {

    int v;
    int e;
    int a;
    int b;
    cin >> v >> e;
    Graph g(v + 1);
    for (int i = 1; i <= e; i++) {
        cin >> a >> b;
        g.addEdge(a, b);
    }
    g.dijkstra(1);
    g.printPath(5);
    return 0;
}