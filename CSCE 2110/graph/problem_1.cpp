#include "graph.cpp"
#define vertices_1 7

int main() {
    int graph_1[vertices_1][vertices_1] = {
        {0, 14, INF, INF, 10, INF, 17}, // a -> any edge 
        {14, 0, 9, 10, 3, INF, INF}, // b -> any edge
        {INF, 9, 0, 2, INF, INF, INF}, // c -> any edge
        {INF, 10, 2, 0, INF, 7, INF}, // d -> any edge
        {10, 3, INF, INF, 0, 4, 6}, // e -> any edge
        {INF, INF, INF, 7, 4, 0, 1}, // f -> any edge
        {17, INF, INF, INF, 6, 1, 0} // g -> any edge
    };

    Graph g(vertices_1);
    for (int i = 0; i < vertices_1; i++) {
        for (int j = 0; j < vertices_1; j++) {
            if (graph_1[i][j] != 0) {
                g.addEdge(i, j, graph_1[i][j]);
            }
        }
    }

    std::cout << "Dijkstra's Algorithm (starting from vertex a):\n";
    g.dijkstra(0);
}