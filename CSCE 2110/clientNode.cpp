#include "clientNode.hpp"

ClientNode::ClientNode(){
    client = {"", ' ', 0, 0, ""};
    next = nullptr;
    previous = nullptr;
}

ClientNode::ClientNode(Client client){
    this->client = client;
    next = nullptr;
    previous = nullptr;
}

Client ClientNode::getClient(){
    return client;
}

ClientNode* ClientNode::getNext(){
    return next;
}

ClientNode* ClientNode::getPrevious(){
    return previous;
}

void ClientNode::setClient(Client client){
    this->client = client;
}

void ClientNode::setNext(ClientNode* next){
    this->next = next;
}

void ClientNode::setPrevious(ClientNode* previous){
    this->previous = previous;
}