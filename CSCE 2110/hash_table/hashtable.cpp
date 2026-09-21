#include <iostream>
#include <string>
#include "minivector.cpp"
using namespace std;

struct key_value_pair {
    string s_key = "";
    int i_key = -1;
    int value;
};

class HashTable {
    public:
        // Insert one key-value pair into the hash table (int, int)
        void insert(int key, int value) {
            int index = mid_square(key);
            table[index].add_value({"", key, value});
        }
        // Insert one key-value pair into the hash table (string, int)
        void insert(const string& key, int value) {
            int index = adler32(key) % TABLE_SIZE;
            table[index].add_value({key, -1, value});
        }
        // Print the hash table, ignoring any empty indices
        void print() {
            for (int i = 0; i < TABLE_SIZE; ++i) {
                if (table[i].get_size() > 0) {
                    cout << "Index " << i << ": ";
                    table[i].print();
                    cout << "NULL" << endl;
                }
            }
        }
        // Search for a value by key and return the value if found, or -1 if not found (int key)
        int search(int key, int value) {
            int index = mid_square(key);
            for (int i = 0; i < table[index].get_size(); ++i) {
                if (table[index][i].i_key == key && table[index][i].value == value) {
                    return table[index][i].value;
                }
            }
            return -1; // Not found
        }
        // Search for a value by key and return the value if found, or -1 if not found (string key)
        int search(const string& key, int value) {
            int index = adler32(key) % TABLE_SIZE;
            for (int i = 0; i < table[index].get_size(); ++i) {
                if (table[index][i].s_key == key && table[index][i].value == value) {
                    return table[index][i].value;
                }
            }
            return -1; // Not found
        }
        // Delete a key-value pair from the hash table (int key)
        void delete_value(int key, int value) {
            int index = mid_square(key);
            for (int i = 0; i < table[index].get_size(); ++i) {
                if (table[index][i].i_key == key && table[index][i].value == value) {
                    table[index].remove_at(i);
                    return;
                }
            }
        }
        // Delete a key-value pair from the hash table (string key)
        void delete_value(const string& key, int value) {
            int index = adler32(key) % TABLE_SIZE;
            for (int i = 0; i < table[index].get_size(); ++i) {
                if (table[index][i].s_key == key && table[index][i].value == value) {
                    table[index].remove_at(i);
                    return;
                }
            }
        }
    private:
        static const int TABLE_SIZE = 100;
        MiniVector<key_value_pair> table[TABLE_SIZE];
        int mid_square(int key) {
            int squared = key * key;
            int mid = (squared / 100) % 100;
            return mid;
        }
        int adler32(const string& str) {
            const int MOD_ADLER = 65521;
            int a = 1, b = 0;
            for (char c : str) {
                a = (a + c) % MOD_ADLER;
                b = (b + a) % MOD_ADLER;
            }
            return (b << 16) | a;
        }
};