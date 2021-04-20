#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include <unordered_map>
#include "WareHouse.cpp"

using namespace std;

class WareHouseHash {
private:
    int a;
    int b;
    int p;
    int m;

    vector<vector<WareHouse>>          Hash_table;

    vector<vector<int>>                Second_Slot_Info;


public:
    WareHouseHash(int prime, int slot_size) {
        m = slot_size;
        p = prime;
        srand((unsigned)time(NULL));
        a = 1 + rand() % (p - 1);
        b = rand() % p;


        Hash_table.resize(m);
        Second_Slot_Info.resize(m);
        for (int i = 0; i < m; i++) {
            vector<int> sj(3);
            int aj = 1 + rand() % (p - 1);
            int bj = rand() % p;
            sj[0] = 0;
            sj[1] = aj;
            sj[2] = bj;
            Second_Slot_Info[i] = sj;
            vector<WareHouse> second_hash;
            Hash_table[i] = second_hash;
        }
    };
    ~WareHouseHash() {
        
    };

    // int NameToKey (string name) {
    //     int key = hs(name);
    //     // if (key < 0) {
    //     //     cout << "nagative nameTokey :" << key << endl;
    //     // }
    //     int result = abs(key);
    //     //cout << name << " -> " << result << endl;
    //     return result;
    // }

    int Hash_i(int key) {
        return ((a * key + b) % p) % m;
    }

    int Hash_j(int key) {
        int aj = Second_Slot_Info[Hash_i(key)][1];
        int bj = Second_Slot_Info[Hash_i(key)][2];
        int mj = Second_Slot_Info[Hash_i(key)][0];

        return ((aj * key + bj) % p) % (mj * mj);
    }

    void Add_All(vector<WareHouse> warehouses) {
        for (int i = 0; i < warehouses.size(); i++) {
            int key = warehouses[i].get_sn();
            Second_Slot_Info[Hash_i(key)][0] ++;
        }

        for (int i = 0; i < Hash_table.size(); i++) {
            Hash_table[i].resize( ((Second_Slot_Info[i][0]) * (Second_Slot_Info[i][0])) );
        }

        for (int i = 0; i < warehouses.size(); i++) {
            int ki = Hash_i(warehouses[i].get_sn());
            int kj = Hash_j(warehouses[i].get_sn());
            // cout << "name :" <<  warehouses[i].get_name() << ": ki" << " -> " << ki << " kj" << " -> " << kj << endl;
            Hash_table[ki][kj] = warehouses[i];
        }         
    }

    WareHouse Search_Warehouse(int key) {
        return Hash_table[Hash_i(key)][Hash_j(key)];
    }
};




