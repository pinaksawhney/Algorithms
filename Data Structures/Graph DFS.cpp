// DFS traversal on graph
// Time complexity : O(|V|+|E|)
// Space complexity : O(|V|)
#include <iostream>
#include <list>
using namespace std;

class Graph {
private:
    int V;
    list<int> *adj;

    void explore(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        for (auto i = adj->begin(); i != adj->end(); i++) {
            if(!visited[*i]){
                explore(*i,visited);
            }
        }
    }
public:
        Graph(int V){
            this->V = V;
            adj = new list<int>[V];
        };
        // add edge to the graph
        void addEdge(int v, int w){
            adj[v].push_back(w);
        }
        // prints dfs of complete graph
        void DFS(){
            bool* visited = new bool[V];
            for (int i = 0; i < V; i++)
                visited[i] = false;

            for(int i=0;i<V;i++){
                if(!visited[i]){
                    explore(i,visited);
                }
            }
        }
};



int main() {
    Graph g(6);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 4);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(0, 3);
    g.DFS();
    return 0;
}
