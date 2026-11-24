#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2627_P1/ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
        int max;
        ListLinked<TableEntry<V>>* table;

        int h(std::string key) {
            int sum = 0;
            for (int i = 0; i < (int)key.size(); i++) {
                sum += int(key.at(i));
            }
            return sum % max;
        }

    public:
        HashTable(int size) {
            table = new ListLinked<TableEntry<V>>[size];
            n = 0;
            max = size;
        }

        ~HashTable() {
            delete[] table;
        }

        int capacity() {
            return max;
        }

        void insert(std::string key, V value) override {
            int b = h(key);
            if (table[b].search(TableEntry<V>(key)) != -1) {
                throw std::runtime_error("Key '" + key + "' already exists");
            }
            table[b].prepend(TableEntry<V>(key, value));
            n++;
        }

        V search(std::string key) override {
            int b = h(key);
            int pos = table[b].search(TableEntry<V>(key));
            if (pos == -1) {
                throw std::runtime_error("Key '" + key + "' not found");
            }
            return table[b].get(pos).value;
        }

        V remove(std::string key) override {
            int b = h(key);
            int pos = table[b].search(TableEntry<V>(key));
            if (pos == -1) {
                throw std::runtime_error("Key '" + key + "' not found");
            }
            V value = table[b].remove(pos).value;
            n--;
            return value;
        }

        int entries() override {
            return n;
        }

        V operator[](std::string key) {
            return search(key);
        }

        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
            out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]" << std::endl;
            out << "==============" << std::endl << std::endl;
            for (int i = 0; i < th.max; i++) {
                out << "== Cubeta " << i << " ==" << std::endl << std::endl;
                out << th.table[i] << std::endl << std::endl;
            }
            out << "==============" << std::endl;
            return out;
        }
};

#endif
