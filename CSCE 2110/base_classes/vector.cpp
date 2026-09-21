template <typename T>
class GenericVector {
    public:
        // Constructor: initializes an empty vector with initial capacity of 1
        GenericVector() : size(0), capacity(1) {
            data = new int[capacity];
        }

        // Destructor: frees the dynamically allocated array
        ~GenericVector() {
            delete[] data;
        }

        // Overloaded subscript operator to access elements by index
        T& operator[](int i) {
            return data[i];
        }

        // Adds a new value to the end of the vector, resizing if necessary
        void add_value(T value) {
            if (size == capacity) {
                capacity *= 2;
                int* new_data = new int[capacity];
                for (int i = 0; i < size; ++i) new_data[i] = data[i];
                delete[] data;
                data = new_data;
            }
            data[size] = value;
            size++;
        }

        // Removes the element at the specified index, shifting subsequent elements left
        void remove_at(int index) {
            if (index < 0 || index >= size) {
                cerr << "Out of bounds" << endl;
                return;
            }
            for (int i = index; i < size - 1; ++i) data[i] = data[i + 1];
            size--;
        }

        // Returns the current number of elements in the vector
        int get_size() {
            return size;
        }

        // Checks if the vector is empty
        bool empty() {
            return size == 0;
        }

        // Returns the current capacity of the vector
        int get_capacity(int index) {
            return capacity;
        }
    private:
        T* data;
        int size;
        int capacity;
};