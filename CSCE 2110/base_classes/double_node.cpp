template <typename T>
class Node {
    public:
        // Default constructor: initializes a node with null pointers
        Node() {
            next = nullptr;
            prev = nullptr;
        }

        // Parameterized constructor: initializes a node with data and null pointers
        Node(T data) {
            this->data = data;
            next = nullptr;
            prev = nullptr;
        }

        // Returns the data stored in this node
        T getData() {
            return data;
        }

        // Returns the pointer to the next node
        Node* getNext() {
            return next;
        }

        // Returns the pointer to the previous node (for doubly-linked lists)
        Node* getPrevious() {
            return prev;
        }

        // Sets the data for this node
        void setData(T data) {
            this->data = data;
        }

        // Sets the pointer to the next node
        void setNext(Node* next) {
            this->next = next;
        }

        // Sets the pointer to the previous node (for doubly-linked lists)
        void setPrevious(Node* prev) {
            this->prev = prev;
        }
    private:
        T data;
        Node* next;
        Node* prev;
};