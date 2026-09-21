#include "clientStack.hpp"

ClientStack::ClientStack() {
    top = nullptr;
}

void ClientStack::push(Client client) {
    ClientNode* newNode = new ClientNode(client);
    newNode->setNext(top);
    top = newNode;
}

Client ClientStack::pop() {
    if (top == nullptr) {
        throw runtime_error("Stack is empty.");
    }
    ClientNode* temp = top;
    Client client = temp->getClient();
    top = top->getNext();
    delete temp;
    return client;
}

Client ClientStack::peek() {
    if (top == nullptr) {
        throw runtime_error("Stack is empty.");
    }
    return top->getClient();
}

bool ClientStack::isEmpty() {
    return top == nullptr;
}