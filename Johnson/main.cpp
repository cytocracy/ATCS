#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void SCC();
    void cycles();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st, bool stackMember[]){
    static int time = 0;
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;

    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;
        if(disc[v] == -1){
            SCCUtil(v, disc, low, st, stackMember);
            low[u] = min(low[u], low[v]);
        }
        else if(stackMember[v] == true){
            low[u] = min(low[u], disc[v]);
        }
    }

    int w = 0;
    if(low[u] == disc[u]){
        while(st->top() != u){
            w = (int)st->top();
            cout << w << " ";
            stackMember[w] = false;
            st->pop();
        }
        w = (int)st->top();
        cout << w << endl;
        stackMember[w] = false;
        st->pop();
    }
}

void Graph::SCC(){
    int *disc = new int[V];
    int *low = new int[V];
    bool *stackMember = new bool[V];
    stack<int> *st = new stack<int>();

    for(int i = 0; i < V; i++){
        disc[i] = -1;
        low[i] = -1;
        stackMember[i] = false;
    }

    for(int i = 0; i < V; i++)
        if(disc[i] == -1)
            SCCUtil(i, disc, low, st, stackMember);

}

void Graph::cycles(){
    stack<int> stack;
    set<int> blocked;
    set<int> blockedMap[V];

}



int main() {
    cout << "Hello, World!" << endl;

    Graph g(10);
    g.addEdge(1,8);
    g.addEdge(8,9);
    g.addEdge(1,2);
    g.addEdge(2,7);
    g.addEdge(1,5);
    g.addEdge(2,3);
    g.addEdge(3,2);
    g.addEdge(3,4);
    g.addEdge(3,6);
    g.addEdge(4,5);
    g.addEdge(6,4);
    g.addEdge(3,1);
    g.addEdge(5,2);
    g.addEdge(2,9);
    g.addEdge(9,8);
    cout << "here" << endl;
    g.SCC();



    return 0;
}
