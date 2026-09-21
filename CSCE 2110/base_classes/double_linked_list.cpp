#include "double_node.cpp"

template <typename T>
class DoubleLinkedList {
    public:
        // Constructor: initializes an empty doubly-linked list with head and tail pointers
        DoubleLinkedList() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        // Inserts a new node with data at the beginning. Updates both next and previous pointers
        void insertAtBeginning(T data) {
            Node* newNode = new Node(data);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->setNext(head);
                head->setPrevious(newNode);
                head = newNode;
            }
            size++;
        }

        // Inserts a new node with data at the end. Updates both next and previous pointers
        void insertAtEnd(T data) {
            Node* newNode = new Node(data);
            if (tail == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->setNext(newNode);
                newNode->setPrevious(tail);
                tail = newNode;
            }
            size++;
        }

        // Inserts a new node with data at the specified index. Updates both next and previous pointers. Throws out_of_range if index is invalid
        void insert(T data, int i) {
            if (i < 0 || i > size) {
                throw out_of_range("Index out of range.");
            }
            if (i == 0) {
                insertAtBeginning(data);
                return;
            }
            if (i == size) {
                insertAtEnd(data);
                return;
            }
            Node* newNode = new Node(data);
            Node* current = head;
            for (int j = 0; j < i - 1; j++) {
                current = current->getNext();
            }
            newNode->setNext(current->getNext());
            newNode->setPrevious(current);
            current->getNext()->setPrevious(newNode);
            current->setNext(newNode);
            size++;
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
            return tail;
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

        // Reverses the items in the doubly-linked list
        void reverse() {
            Node* prev = nullptr;
            Node* current = head;
            Node* next = nullptr;

            while (current != nullptr) {
                next = current->getNext();
                current->setNext(prev);
                current->setPrevious(next);
                prev = current;
                current = next;
            }
            head = prev;
        }
    private:
        Node* head;
        Node* tail;
        int size;
};