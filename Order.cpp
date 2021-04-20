#ifndef _Order_CPP_
#define _Order_CPP_

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Location.cpp"


using namespace std;

class Order {
private:
    int TimeStamp;
    string productName;
    int productSN;
    Location location;
public:
    Order() {
        TimeStamp = -999;
        productName = "NULL";
        Location a;
        location = a;
        productSN = 0;       
    }
    Order(int t,string name, int x, int y, int sn) {
        TimeStamp = t; productName = name; productSN = sn;
        Location l(x,y); location = l;
    };
    ~Order() {};

    int get_Time() {
        return TimeStamp;
    }

    string get_Product() {
        return productName;
    }

    Location get_location() {
        return location;
    }

    int get_SN() {
        return productSN;
    }
};

#endif

