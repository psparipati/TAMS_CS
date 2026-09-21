#include "graph.cpp"
#define vertices_2 10

int main() {
    int graph_2[vertices_2][vertices_2] = {
        {0, 8, 3, 5, INF, INF, INF, INF, INF, INF}, // a -> any edge
        {8, 0, INF, INF, INF, 2, INF, INF, INF, 7}, // b -> any edge
        {3, INF, 0, INF, INF, INF, 7, 6, INF, INF}, // c -> any edge
        {5, INF, INF, 0, 2, INF, INF, INF, 7, INF}, // d -> any edge
        {INF, INF, INF, 2, 0, 5, INF, 4, INF, INF}, // f -> any edge
        {INF, 2, INF, INF, 5, 0, 8, INF, INF, INF}, // h -> any edge 
        {INF, INF, 7, INF, INF, 8, 0, INF, 4, INF}, // i -> any edge
        {INF, INF, 6, INF, 4, INF, INF, 0, INF, INF}, // j -> any edge
        {INF, INF, INF, 7, INF, INF, 4, INF, 0, 9}, // k -> any edge
        {INF, 7, INF, INF, INF, INF, INF, INF, 9, 0} // l -> any edge
    };

    Graph g(vertices_2);
    for (int i = 0; i < vertices_2; i++) {
        for (int j = 0; j < vertices_2; j++) {
            if (graph_2[i][j] != 0) {
                g.addEdge(i, j, graph_2[i][j]);
            }
        }
    }

    std::cout << "Prim's Algorithm (Minimum Spanning Tree):\n";
    g.primMST();
}