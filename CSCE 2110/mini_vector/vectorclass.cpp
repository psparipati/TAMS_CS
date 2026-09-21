#include <iostream>
using namespace std;

class MiniIntVector {
    public:
        MiniIntVector() : size(0), capacity(2) {
            data = new int[capacity];
        }

        ~MiniIntVector() {
            delete[] data;
        }

        void add_value(int value) {
            if (size == capacity) {
                capacity *= 2;
                int* new_data = new int[capacity];
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

        int& operator[](int i) {
            return data[i];
        }

        void print() {
            for (int i = 0; i < size; ++i) {
                cout << data[i] << " ";
            }
        }
    private:
        int* data;
        int size;
        int capacity;
};

int main() {
    MiniIntVector vec;
    vec.add_value(10);
    vec.add_value(15);
    vec.add_value(20);
    vec.add_value(25);
    vec.add_value(30);
    cout << "Initial Vector: ";
    vec.print();
    cout << endl;
    vec.remove_at(1);
    vec.remove_at(2);
    cout << "After Removals: ";
    vec.print();
    cout << endl;
    return 0;
}