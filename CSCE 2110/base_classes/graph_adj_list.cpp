#include "single_node.cpp"
#include "queue.cpp"
#define INF 1e9
#include <iostream>

// Structure to store a weighted edge
struct Edge {
    int vertex;
    double weight;
    
    Edge(int v = 0, double w = 0.0) : vertex(v), weight(w) {}
};

class Graph {
    public:
        Graph(int vertices) {
            V = vertices;
            adj_list = new Node<Edge>*[V];
            for (int i = 0; i < V; i++) {
                adj_list[i] = nullptr;
            }
        }

        void addEdge(int u, int v, int weight = 1) {
            Node<Edge>* newNode = new Node<Edge>(Edge(v, weight));
            newNode->setNext(adj_list[u]);
            adj_list[u] = newNode;
        }

        void topologicalSort() {
            int indegree[V] = {0};

            // Step 1: Compute indegrees
            for (int i = 0; i < V; i++) {
                Node<Edge>* temp = adj_list[i];
                while (temp != nullptr) {
                    indegree[temp->getData().vertex]++;
                    temp = temp->getNext();
                }
            }

            // Step 2: Initialize queue with indegree 0
            Queue<int> q(V);
            for (int i = 0; i < V; i++) {
                if (indegree[i] == 0) {
                    q.enqueue(i);
                }
            }

            // Step 3: Process queue
            int count = 0;

            std::cout << "Topological Order: ";

            while (!q.isEmpty()) {
                int u = q.dequeue();
                std::cout << u << " ";
                count++;

                Node<Edge>* temp = adj_list[u];
                while (temp != nullptr) {
                    Edge edge = temp->getData();
                    indegree[edge.vertex]--;

                    if (indegree[edge.vertex] == 0) {
                        q.enqueue(edge.vertex);
                    }

                    temp = temp->getNext();
                }
            }

            // Step 4: Check for cycle
            if (count != V) {
                std::cout << "\nGraph has a cycle. No valid topological ordering.\n";
            }

            std::cout << std::endl;
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

                Node<Edge>* temp = adj_list[u];
                while (temp != nullptr) {
                    Edge edge = temp->getData();
                    int v = edge.vertex;
                    double weight = edge.weight;
                    if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                    temp = temp->getNext();
                }
            }

            std::cout << "Vertex \t Distance from Source\n";
            for (int i = 0; i < V; i++) {
                std::cout << i << "\t\t" << dist[i] << "\n";
            }
        }

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

                Node<Edge>* temp = adj_list[u];
                while (temp != nullptr) {
                    Edge edge = temp->getData();
                    int v = edge.vertex;
                    double weight = edge.weight;
                    if (!mstSet[v] && weight < key[v]) {
                        parent[v] = u;
                        key[v] = weight;
                    }
                    temp = temp->getNext();
                }
            }

            std::cout << "Edge \tWeight\n";
            for (int i = 1; i < V; i++) {
                std::cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
            }
        }
    private:
        int V;
        Node<Edge>** adj_list;
};