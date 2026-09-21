#include <iostream>
#define INF 100000

class Graph {
    public:
        Graph(int vertices) {
            V = vertices;
            adj_matrix = new int*[V];
            for (int i = 0; i < V; i++) {
                adj_matrix[i] = new int[V];
                for (int j = 0; j < V; j++) {
                    adj_matrix[i][j] = 0;
                }
            }
        }

        void addEdge(int u, int v, int weight) {
            adj_matrix[u][v] = weight;
        }
        
        int minDistance(int dist[], bool visited[]) {
            int min = INF, min_index = -1;

            for (int i = 0; i < V; i++) {
                if (!visited[i] && dist[i] < min) {
                    min = dist[i];
                    min_index = i;
                }
            }
            return min_index;
        }

        // Solves problem one using Dijkstra's algorithm
        void dijkstra(int start) {
            int dist[V];
            bool visited[V];

            for (int i = 0; i < V; i++) {
                dist[i] = INF;
                visited[i] = false;
            }
            dist[start] = 0;

            for (int count = 0; count < V - 1; count++) {
                int u = minDistance(dist, visited);
                visited[u] = true;

                for (int v = 0; v < V; v++) {
                    if (!visited[v] && adj_matrix[u][v] != 0 && dist[u] != INF && dist[u] + adj_matrix[u][v] < dist[v]) {
                        dist[v] = dist[u] + adj_matrix[u][v];
                    }
                }
            }

            std::cout << "Vertex \tDistance from Source\n";
            for (int i = 0; i < V; i++) {
                std::cout << i << "\t" << dist[i] << "\n";
            }
        }

        // Solves problem two using Prim's algorithm
        void primMST() {
            int parent[V];
            int key[V];
            bool mstSet[V];

            for (int i = 0; i < V; i++) {
                key[i] = INF;
                mstSet[i] = false;
            }

            key[0] = 0;
            parent[0] = -1;
            
            for (int count = 0; count < V - 1; count++) {
                int u = minDistance(key, mstSet);
                mstSet[u] = true;

                for (int v = 0; v < V; v++) {
                    if (adj_matrix[u][v] && !mstSet[v] && adj_matrix[u][v] < key[v]) {
                        parent[v] = u;
                        key[v] = adj_matrix[u][v];
                    }
                }
            }

            std::cout << "Edge \tWeight\n";
            for (int i = 1; i < V; i++) {
                std::cout << parent[i] << " - " << i << "\t" <<
                    adj_matrix[parent[i]][i] << "\n";
            }
        }
    private:
        int V;
        int** adj_matrix;
};