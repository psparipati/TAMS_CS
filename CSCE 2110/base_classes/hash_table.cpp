#include "vector.cpp"

// This is an integer hash table, but any data type works.
class HashTable {
    public:
        // Insert one key-value pair into the hash table (int, int)
        void insert(int key, int value) {
            int index = mid_square(key);
            table[index].add_value(value);
        }
        // Search for a value by key and return the value if found, or -1 if not found
        int search(int key, int value) {
            int index = mid_square(key);
            for (int i = 0; i < table[index].get_size(); ++i) {
                if (table[index][i] == value) {
                    return table[index][i];
                }
            }
            return -1; // Not found
        }
        // Delete a key-value pair from the hash table
        void delete_value(int key, int value) {
            int index = mid_square(key);
            for (int i = 0; i < table[index].get_size(); ++i) {
                if (table[index][i] == value) {
                    table[index].remove_at(i);
                    return;
                }
            }
        }
    private:
        static const int TABLE_SIZE = 100;
        GenericVector<int> table[TABLE_SIZE];
        int mid_square(int key) {
            int squared = key * key;
            int mid = (squared / 100) % 100;
            return mid;
        }
        /*
        Other hash functions (not required, but really cool):
        int adler32(const string& str) {
            const int MOD_ADLER = 65521;
            int a = 1, b = 0;
            for (char c : str) {
                a = (a + c) % MOD_ADLER;
                b = (b + a) % MOD_ADLER;
            }
            return (b << 16) | a;
        }
        int modulo_hash(int key) {
            return key % TABLE_SIZE;
        }
        int multiplicative(string key) {
            unsigned long hash = 5381;
            for (char c : key) {
                hash = ((hash << 5) + hash) + c; // hash * 33 + c
            }
            return hash % TABLE_SIZE;
        }
        int direct_hash(int key) {
            return key; // Not really the best option for TABLE_SIZE = 100
        }
        */
};