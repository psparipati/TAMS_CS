template <typename T>
class Node {
    public:
        // Default constructor: initializes a node with null pointer
        Node() {
            next = nullptr;
        }

        // Parameterized constructor: initializes a node with data and null pointer
        Node(T data) {
            this->data = data;
            next = nullptr;
        }

        // Returns the data stored in this node
        T getData() {
            return data;
        }

        // Returns the pointer to the next node
        Node* getNext() {
            return next;
        }

        // Sets the data for this node
        void setData(T data) {
            this->data = data;
        }

        // Sets the pointer to the next node
        void setNext(Node* next) {
            this->next = next;
        }
    private:
        T data;
        Node* next;
};