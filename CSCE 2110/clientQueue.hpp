#ifndef CLIENTQUEUE_HPP
#define CLIENTQUEUE_HPP

#include "clientNode.hpp"

class ClientQueue {
    public:
        ClientQueue();
        void enqueue(Client client);
        Client dequeue();
        Client peek();
        bool isEmpty();
    private:
        ClientNode* front;
        ClientNode* rear;
};

#endif