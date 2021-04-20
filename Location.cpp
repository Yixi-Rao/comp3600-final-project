#ifndef _Location_CPP_
#define _Location_CPP_

#include <string>
#include <iostream>
#include <cstdlib>

class Location {
private:
    int X;
    int Y;
public:
    Location() {
        X = 0;
        Y = 0;
    };
    Location(int x, int y) {
        X = x;
        Y = y;
    }
    ~Location(){};

    int get_X() {
        return X;
    }

    int get_Y() {
        return Y;
    }
};
#endif

