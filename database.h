#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class database{
        //committed transactions
        unordered_map<string, int> memory;
        //current transaction
        unordered_map<string, int> tempMemory;
        bool transaction = false;

    public:
        database();
        void begin_transaction();
        void put(string key, int value);
        int get(string key);
        void commit();
        void rollback();
};
