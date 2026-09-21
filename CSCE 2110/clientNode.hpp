#ifndef CLIENTNODE_HPP
#define CLIENTNODE_HPP

#include <iostream>
#include <string>

using namespace std;

struct Client{
    string clientName;
    char gender;
    int age;
    int familySize;
    string dateOfBirth;
};

class ClientNode {
    public:
        ClientNode();
        ClientNode(Client client);
        Client getClient();
        ClientNode* getNext();
        ClientNode* getPrevious();
        void setClient(Client client);
        void setNext(ClientNode* next);
        void setPrevious(ClientNode* previous);
    private:
        Client client;
        ClientNode* next;
        ClientNode* previous;
};

#endif