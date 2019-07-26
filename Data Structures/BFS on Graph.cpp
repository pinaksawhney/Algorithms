#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
private:
    int V;
    list<int> *adj;

public:

    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int s){
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }

        queue<int> q;
        visited[s] = true;
        q.push(s);
        while (!q.empty()) {
            int f = q.front();
            cout<<f<<" ";
            q.pop();
            for (auto j = adj[f].begin(); j != adj[f].end(); ++j) {
                if (!visited[*j]) {
                    visited[*j] = true;
                    q.push(*j);
                }
            }
        }
    }

};

int main(){


    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);

    return 0;
}