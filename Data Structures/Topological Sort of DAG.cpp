// topological sort of DAG
// Time Complexity: O(V+E)

#include<iostream>
#include <list>
#include <stack>
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

    void topologicalSortUtil(int v, bool visited[],stack<int> &st) {
        visited[v] = true;
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]) {
                topologicalSortUtil(*i, visited, st);
            }
        }
    st.push(v);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void topologicalSort() {
        stack<int> st;
        bool *visited = new bool[V];
        for (int v = 0; v < V; v++)
            visited[v] = false;

        for (int v = 1; v < V; v++) {
            if (!visited[v]) {
                topologicalSortUtil(v, visited, st);
            }
        }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topologicalSort();
    return 0;
}