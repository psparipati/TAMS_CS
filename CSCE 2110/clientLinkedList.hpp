#ifndef CLIENTLINKEDLIST_HPP
#define CLIENTLINKEDLIST_HPP

#include "clientNode.hpp"

class ClientLinkedList {
    public:
        // Manager 1
        ClientLinkedList();
        void insertAtBeginning(Client client);
        void insertAtEnd(Client client);
        void insertAfterClient(Client client, Client afterClient);
        Client getFirstClient();
        Client getLastClient();
        ClientNode* searchByName(string name);
        ClientNode* searchByAge(int age);
        ClientNode* searchByGender(char gender);
    private:
        ClientNode* head;
        ClientNode* tail;
};

#endif