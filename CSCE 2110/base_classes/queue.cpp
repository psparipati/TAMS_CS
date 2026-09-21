template <typename T>
class Queue {
    public:
        // Constructor: initializes a circular queue with given capacity
        Queue(int size) {
            arr = new T[size];
            capacity = size;
            front = 0;
            rear = -1;
            count = 0;
        }

        // Destructor: frees the dynamically allocated array
        ~Queue() {
            delete[] arr;
        }

        // Adds an element to the rear of the queue using circular indexing. Throws overflow_error if queue is full
        void enqueue(T x) {
            if (count == capacity) {
                throw std::overflow_error("Queue overflow");
            }
            rear = (rear + 1) % capacity;
            arr[rear] = x;
            count++;
        }

        // Removes and returns the front element from the queue using circular indexing. Throws underflow_error if queue is empty
        T dequeue() {
            if (count == 0) {
                throw std::underflow_error("Queue underflow");
            }
            T x = arr[front];
            front = (front + 1) % capacity;
            count--;
            return x;
        }

        // Returns the front element without removing it. Throws underflow_error if queue is empty
        T peek() {
            if (count == 0) {
                throw std::underflow_error("Queue is empty");
            }
            return arr[front];
        }

        // Checks if the queue is empty
        bool isEmpty() {
            return count == 0;
        }

        // Returns the number of elements currently in the queue
        int size() {
            return count;
        }

    private:
        T* arr;
        int front;
        int rear;
        int count;
        int capacity;
};