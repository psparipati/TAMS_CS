#include <iostream>
using namespace std;

template <typename T>
class MiniVector {
    public:
        MiniVector() : size(0), capacity(1) {
            data = new T[capacity];
        }
        ~MiniVector() {
            delete[] data;
        }
        void add_value(T value) {
            if (size == capacity) {
                capacity *= 2;
                T* new_data = new T[capacity];
                for (int i = 0; i < size; ++i) {
                    new_data[i] = data[i];
                }
                delete[] data;
                data = new_data;
            }
            data[size++] = value;
        }
        void remove_at(int index) {
            if (index < 0 || index >= size) {
                cerr << "Index out of bounds" << endl;
                return;
            }
            for (int i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            --size;
        }
        void print() {
            for (int i = 0; i < size; ++i) {
                cout << data[i] << ", ";
            }
        }
        T& operator[](int i) {
            return data[i];
        }
        int get_size() const {
            return size;
        }
    private:
        T* data;
        int size;
        int capacity;
};