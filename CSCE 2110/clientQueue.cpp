#include "clientQueue.hpp"

ClientQueue::ClientQueue() {
    front = nullptr;
    rear = nullptr;
}

void ClientQueue::enqueue(Client client) {
    ClientNode* newNode = new ClientNode(client);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->setNext(newNode);
        rear = newNode;
    }
}

Client ClientQueue::dequeue() {
    if (front == nullptr) {
        throw runtime_error("Queue is empty.");
    }
    ClientNode* temp = front;
    Client client = temp->getClient();
    front = front->getNext();
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    return client;
}

Client ClientQueue::peek() {
    if (front == nullptr) {
        throw runtime_error("Queue is empty.");
    }
    return front->getClient();
}

bool ClientQueue::isEmpty() {
    return front == nullptr;
}