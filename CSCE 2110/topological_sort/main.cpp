#include "graph.cpp"
#include <fstream>
#include <iostream>

void edges_from_file(Graph graph, std::ifstream& infile) {
    int u, v;
    while (infile >> u >> v) {
        graph.addEdge(u, v);
    }
}

int main() {
    std::ifstream adj_list("adj_list");
    if (!adj_list) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    
    int num_vertices;
    adj_list >> num_vertices;
    Graph graph(num_vertices);

    edges_from_file(graph, adj_list);
    graph.topologicalSort();

    return 0;
}