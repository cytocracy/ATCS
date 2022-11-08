#include <iostream>
#include <set>
#include <queue> // for priority_queue
using namespace std;

struct Edge {
    int weight;
    string start;
    string end;
    Edge(int weight, string start, string end) {
        this->weight = weight;
        this->start = start; 
        this->end = end;
    }
    bool operator < (const Edge& rhs) const {
        return weight > rhs.weight;
    }
};

void initializeGraph(priority_queue<Edge> & graph);
void primsAlgorithm(priority_queue<Edge> & graph, int numNodes);

int main() {
    cout << "Prim's Algorithm!" << endl;
    priority_queue<Edge> graph;
    initializeGraph(graph);
    primsAlgorithm(graph, 6);
    cout << "DONE" << endl;
    return 0;
}

void primsAlgorithm(priority_queue<Edge> & graph, int numNodes) {
    priority_queue<Edge> save;
    set<string> visited;
    visited.insert("A");
    while (visited.size() < numNodes){
        Edge e = graph.top();
        graph.pop();
        if (visited.count(e.start) + visited.count(e.end) == 1) {
            cout << e.start << e.end << " (" << e.weight << ")" << endl;
            visited.insert(e.start);
            visited.insert(e.end);
            while (!save.empty()){
                graph.push(save.top());
                save.pop();
            }
        } else {
            save.push(e);
        }
    }
}

void initializeGraph(priority_queue<Edge> & graph) {
    graph.push(Edge(5, "A", "B"));
    graph.push(Edge(2, "A", "D"));
    graph.push(Edge(4, "B", "C"));
    graph.push(Edge(2, "B", "E"));
    graph.push(Edge(8, "D", "B"));
    graph.push(Edge(7, "D", "E"));
    graph.push(Edge(3, "C", "F"));
    graph.push(Edge(6, "C", "E"));
    graph.push(Edge(1, "E", "F"));
}
