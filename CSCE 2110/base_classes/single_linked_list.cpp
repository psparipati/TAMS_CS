#include "single_node.cpp"

template <typename T>
class SingleLinkedList {
    public:
        // Constructor: initializes an empty linked list
        SingleLinkedList() {
            head = nullptr;
            size = 0;
        }

        // Inserts a new node with the given data at the beginning of the list
        void insertAtBeginning(T data) {
            Node* newNode = new Node(data);
            newNode->setNext(head);
            head = newNode;
            size++;
        }

        // Inserts a new node with the given data at the end of the list. Traverses to the last node, then appends
        void insertAtEnd(T data) {
            Node* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
            }
            else {
                Node* current = head;
                while (current->getNext() != nullptr) {
                    current = current->getNext();
                }
                current->setNext(newNode);
            }
            size++;
        }

        // Inserts a new node with data at the specified index. Throws out_of_range if index is invalid
        void insert(T data, int i) {
            if (i < 0 || i > size) {
                throw out_of_range("Index out of range.");
            }
            if (i == 0) {
                insertAtBeginning(data);
                return;
            }
            Node* newNode = new Node(data);
            Node* current = head;
            for (int j = 0; j < i - 1; j++) {
                current = current->getNext();
            }
            newNode->setNext(current->getNext());
            current->setNext(newNode);
            size++;
        }

        // Deletes the first node containing the given data. Returns true if a node was deleted, false otherwise
        bool deleteNode(T data) {
            if (head == nullptr) {
                return false;
            }
            if (head->getData() == data) {
                Node* temp = head;
                head = head->getNext();
                delete temp;
                size--;
                return true;
            }
            Node* current = head;
            while (current->getNext() != nullptr) {
                if (current->getNext()->getData() == data) {
                    Node* temp = current->getNext();
                    current->setNext(current->getNext()->getNext());
                    delete temp;
                    size--;
                    return true;
                }
                current = current->getNext();
            }
            return false;
        }

        // Searches for a node containing the given data. Returns the node if found, nullptr otherwise
        Node* search(T data) {
            Node* current = head;
            while (current != nullptr) {
                if (current->getData() == data) {
                    return current;
                }
                current = current->getNext();
            }
            return nullptr;
        }

        // Returns the first node (head) of the list
        Node* getFirst() {
            return head;
        }

        // Returns the last node (tail) of the list
        Node* getLast() {
            Node* current = head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            return current;
        }

        // Returns the node at the specified index. Throws out_of_range if index is invalid
        Node* get(int i) {
            if (i < 0 || i >= size) {
                throw out_of_range("Index out of range.");
            }
            Node* current = head;
            for (int j = 0; j < i; j++) {
                current = current->getNext();
            }
            return current;
        }

        // Reverses the items in the linked list
        void reverse() {
            Node* prev = nullptr;
            Node* current = head;
            Node* next = nullptr;

            while (current != nullptr) {
                next = current->getNext();
                current->setNext(prev);
                prev = current;
                current = next;
            }
            head = prev;
        }
    private:
        Node* head;
        int size;
};