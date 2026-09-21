#include "clientLinkedList.hpp"

ClientLinkedList::ClientLinkedList() {
    head = nullptr;
    tail = nullptr;
}

void ClientLinkedList::insertAtBeginning(Client client) {
    ClientNode* newNode = new ClientNode(client);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->setNext(head);
        head->setPrevious(newNode);
        head = newNode;
    }
}

void ClientLinkedList::insertAtEnd(Client client) {
    ClientNode* newNode = new ClientNode(client);
    if (tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->setNext(newNode);
        newNode->setPrevious(tail);
        tail = newNode;
    }
}

void ClientLinkedList::insertAfterClient(Client client, Client afterClient) {
    ClientNode* current = head;
    while (current != nullptr) {
        if (current->getClient().clientName == afterClient.clientName) {
            ClientNode* newNode = new ClientNode(client);
            newNode->setNext(current->getNext());
            newNode->setPrevious(current);
            if (current->getNext() != nullptr) {
                current->getNext()->setPrevious(newNode);
            }
            current->setNext(newNode);
            if (current == tail) {
                tail = newNode;
            }
            return;
        }
        current = current->getNext();
    }
}

Client ClientLinkedList::getFirstClient() {
    if (head != nullptr) {
        return head->getClient();
    }
    throw runtime_error("No clients in the container.");
}

Client ClientLinkedList::getLastClient() {
    if (tail != nullptr) {
        return tail->getClient();
    }
    throw runtime_error("No clients in the container.");
}

ClientNode* ClientLinkedList::searchByName(string name) {
    ClientNode* current = head;
    while (current != nullptr) {
        if (current->getClient().clientName == name) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

ClientNode* ClientLinkedList::searchByAge(int age) {
    ClientNode* current = head;
    while (current != nullptr) {
        if (current->getClient().age == age) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}

ClientNode* ClientLinkedList::searchByGender(char gender) {
    ClientNode* current = head;
    while (current != nullptr) {
        if (current->getClient().gender == gender) {
            return current;
        }
        current = current->getNext();
    }
    return nullptr;
}