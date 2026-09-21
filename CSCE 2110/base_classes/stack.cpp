template <typename T>
class Stack {
    public:
        // Constructor: initializes a stack with given capacity
        Stack(int size) {
            arr = new T[size];
            capacity = size;
            top = -1;
        }

        // Destructor: frees the dynamically allocated array
        ~Stack() {
            delete[] arr;
        }

        // Adds an element to the top of the stack. Throws overflow_error if stack is full
        void push(T x) {
            if (top == capacity - 1) {
                throw std::overflow_error("Stack overflow");
            }
            arr[++top] = x;
        }

        // Removes and returns the top element from the stack. Throws underflow_error if stack is empty
        T pop() {
            if (top == -1) {
                throw std::underflow_error("Stack underflow");
            }
            return arr[top--];
        }

        // Returns the top element without removing it. Throws underflow_error if stack is empty
        T peek() {
            if (top == -1) {
                throw std::underflow_error("Stack is empty");
            }
            return arr[top];
        }

        // Checks if the stack is empty
        bool isEmpty() {
            return top == -1;
        }

        // Returns the number of elements currently in the stack
        int size() {
            return top + 1;
        }
    private:
        T* arr;
        int top;
        int capacity;
};