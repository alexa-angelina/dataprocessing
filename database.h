#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class database{
        unordered_map<string, int> memory;
        bool transaction = false;

    public:
        database();
        void begin_transaction();
        void put(string key, int value);
        int get(string key);
        void commit();
        void rollback();
};
