#ifndef _WareHouse_CPP_
#define _WareHouse_CPP_
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Location.cpp"

using namespace std;

class WareHouse {
private:
    Location location;
    string name;
    int serial_number;
public:
    WareHouse() {
        Location l(-1,-1);
        location = l;
        name = "Not initialized";
    }
    WareHouse(string WareHouse_name, int map_length, int sn) {
        srand((unsigned)time(NULL));
        int x = rand() % map_length;
        int y = rand() % map_length;
        Location l(x,y);
        location = l;
        serial_number = sn;
        name = WareHouse_name;
    };

    WareHouse(string WareHouse_name, int x, int y, int map_length, int sn) {
        serial_number = sn;
        location = Location(x,y);
        name = WareHouse_name;
    };

    
    ~WareHouse() {

    };
    

    string get_name() {
        return name;
    }

    Location get_location(){
        return location;
    }

    int get_sn() {
        return serial_number;
    }
    
};
#endif



