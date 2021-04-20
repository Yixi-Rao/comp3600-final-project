#ifndef _Address_CPP_
#define _Address_CPP_


#include <iostream>
#include <vector>

using namespace std;

class Address {

private:

    bool visited = false;
    int P_X, P_Y = -1;
    int d = 999999999;

    int X;
    int Y;
    int Left_road = -1;
    int Right_road = -1;
    int Top_road = -1;
    int Down_road = -1;   
    
public:
    Address() {
        X = 0; Y = 0;
    };

    Address(int x, int y, int l, int r, int t, int d) {
        X = x; Y = y; Left_road = l; Right_road = r; Top_road = t; Down_road = d;
    };
    ~Address() {
        
    };

    pair<int,int> get_Parent() {
        pair<int,int> result(P_X,P_Y);
        return result;
    }

    bool get_Visited() {
        return visited;
    }

    int get_D() {
        return d;
    }

    int get_X() {
        return X;
    }

    int get_Y() {
        return Y;
    }

    int get_Left() {
        return Left_road;
    }

    int get_Right() {
        return Right_road;
    }

    int get_Top() {
        return Top_road;
    }

    int get_Down() {
        return Down_road;
    }
// ----------------------------------------------------------------------------------------------------------------------------
    
    void set_Parent(int x, int y) {
        P_X = x; P_Y = y;
    }
    
    void set_Visited (bool v) {
        visited = v;
    }
    
    void set_D (int distance) {
        d = distance;
    }

    void set_X (int x) {
        X = x;
    }

    void set_Y (int y) {
        Y = y;
    }

    void set_Left (int l) {
        Left_road = l;
    }

    void set_Right (int r) {
        Right_road = r;
    }

    void set_Top (int t) {
        Top_road = t;
    }

    void set_Down (int d) {
        Down_road = d;
    }

};

#endif


