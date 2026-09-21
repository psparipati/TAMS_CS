#include "node.cpp"
#include "queue.cpp"
#include <iostream>

class Graph {
    public:
        Graph(int vertices) {
            V = vertices;
            adj = new Node<int>*[V];
            for (int i = 0; i < V; i++) {
                adj[i] = nullptr;
            }
        }

        void addEdge(int u, int v) {
            Node<int>* newNode = new Node<int>(v);
            newNode->setNext(adj[u]);
            adj[u] = newNode;
        }

        void topologicalSort() {
            int indegree[V] = {0};

            // Step 1: Compute indegrees
            for (int i = 0; i < V; i++) {
                Node<int>* temp = adj[i];
                while (temp != nullptr) {
                    indegree[temp->getData()]++;
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

                Node<int>* temp = adj[u];
                while (temp != nullptr) {
                    indegree[temp->getData()]--;

                    if (indegree[temp->getData()] == 0) {
                        q.enqueue(temp->getData());
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
    
    private:
        int V;
        Node<int>** adj;
};