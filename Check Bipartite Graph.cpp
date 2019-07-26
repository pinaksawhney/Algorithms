#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
private:
    int V;
    list<int> *adj;
    int* color;
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        color = new int[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bool isBipartiteUtil(int s) {
        color[s] = 1;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            // check self loop and return false
            //
            for (auto j = adj[f].begin(); j != adj[f].end(); ++j) {
                if(*j==f)
                    return false;
                if (color[*j]==-1) {
                    color[*j] = 1-color[f];
                    q.push(*j);
                }
                else if(color[*j]==color[f])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(){
        for(int i=1;i<V;i++)
            color[i] = -1;
        for(int i=1;i<V;i++) {
            if (color[i] == -1) {
                if (!isBipartiteUtil(i))
                    return false;
            }
        }
        return true;
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
    cout<<g.isBipartite();
    return 0;
}