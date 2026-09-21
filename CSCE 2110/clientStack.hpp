#ifndef CLIENTSTACK_HPP
#define CLIENTSTACK_HPP

#include "clientNode.hpp"

class ClientStack {
    public:
        ClientStack();
        void push(Client client);
        Client pop();
        Client peek();
        bool isEmpty();
    private:
        ClientNode* top;
};

#endif