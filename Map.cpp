#ifndef _Map_CPP_
#define _Map_CPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Address.cpp"



using namespace std;

class Map {

private:
    vector<vector<Address>> Grid_Map;
    int Map_Length;
public:
    Map () {
        Map_Length = 0;
    };
    Map(int n) {
        Map_Length = n;
        Grid_Map.resize(n);
        for (int i = 0; i < Map_Length; i++) {
            vector<Address> tmp(n);
            Grid_Map[i] = tmp;
        }
        
    };

    ~Map() {
       
    };

    void create_random_Map() {
        srand((unsigned)time(NULL));
        for (int i = 0; i < Map_Length; i++) {
            for (int j = 0; j < Map_Length; j++) {
                if (i == 0) {
                    if (j == 0) {
                        int l = rand() % 20;
                        int r = rand() % 20;
                        int t = rand() % 20;
                        int d = rand() % 20;
                        Grid_Map[i][j] = Address(i,j,l,r,t,d); 
                    } else {                      
                        int r = rand() % 20;
                        int t = rand() % 20;
                        int d = rand() % 20;
                        Grid_Map[i][j] = Address(i,j,Grid_Map[i][j - 1].get_Right(),r,t,d); 
                    }                  
                } else {
                    if (j == 0) {
                        int l = rand() % 20;
                        int r = rand() % 20;
                        int d = rand() % 20;
                        Grid_Map[i][j] = Address(i,j,l,r,Grid_Map[i - 1][j].get_Down(),d); 
                    } else {
                        int r = rand() % 20;
                        int d = rand() % 20;
                        Grid_Map[i][j] = Address(i,j,Grid_Map[i][j - 1].get_Right(),r,Grid_Map[i - 1][j].get_Down(),d); 
                    }

                }
            }         
        }      
    }

    void create_uniform_Map() {
        for (int i = 0; i < Map_Length; i++) {
            for (int j = 0; j < Map_Length; j++) {
                Grid_Map[i][j] = Address(i,j,1,1,1,1); 
            }         
        }      
    }

    vector<vector<Address>> get_Map() {
        return Grid_Map;
    }

    int get_Map_size() {
        return Map_Length;
    }

    int get_Map_Distance(int x, int y) {
        return Grid_Map[x][y].get_D();
    }

    pair<int,int> get_Map_Parent(int x, int y) {
        return Grid_Map[x][y].get_Parent();
    }

    bool get_Map_Visited (int x, int y) {
        return Grid_Map[x][y].get_Visited();
    }

    void set_Map_Parent(int x, int y, int px, int py) {
        Grid_Map[x][y].set_Parent (px, py);
    }
    
    void set_Map_Distance(int x, int y, int distance) {
        Grid_Map[x][y].set_D(distance);
    }

    void set_Map_Visited (int x, int y) {
        Grid_Map[x][y].set_Visited(true);
    }

    vector<Address> adjacent_edges(int x, int y) {
        vector<Address> result;
        if (x == 0) {
            if (y == 0) {
                result.resize(2);
                result[0] = Grid_Map[x][y + 1];
                result[1] = Grid_Map[x + 1][y];
            } else if (y == Map_Length - 1) {
                result.resize(2);
                result[0] = Grid_Map[x][y - 1];
                result[1] = Grid_Map[x + 1][y];
            } else {
                result.resize(3);
                result[0] = Grid_Map[x][y - 1];
                result[1] = Grid_Map[x][y + 1];
                result[2] = Grid_Map[x + 1][y];
            }
        } else if (y == 0) {
            if (x == Map_Length - 1) {
                result.resize(2);
                result[0] = Grid_Map[x - 1][y];
                result[1] = Grid_Map[x][y + 1];
            } else {
                result.resize(3);
                result[0] = Grid_Map[x - 1][y];
                result[1] = Grid_Map[x + 1][y];
                result[2] = Grid_Map[x][y + 1];
            }
        } else if (x == Map_Length - 1) {
            if (y == Map_Length - 1) {
                result.resize(2);
                result[0] = Grid_Map[x - 1][y];
                result[1] = Grid_Map[x][y - 1];
            } else {
                result.resize(3);
                result[0] = Grid_Map[x][y - 1];
                result[1] = Grid_Map[x][y + 1];
                result[2] = Grid_Map[x - 1][y];
            }
        } else if (y == Map_Length - 1) {
            result.resize(3);
            result[0] = Grid_Map[x - 1][y];
            result[1] = Grid_Map[x + 1][y];
            result[2] = Grid_Map[x][y - 1];
        } else {
            result.resize(4);
            result[0] = Grid_Map[x - 1][y];
            result[1] = Grid_Map[x][y - 1];
            result[2] = Grid_Map[x + 1][y];
            result[3] = Grid_Map[x][y + 1];
        }

        return result;
    }

    int Two_V_Distance(int x0, int y0, int x1, int y1) {
        if (abs(x0 - x1) > 1 || abs(y0 - y1) > 1) {
            return -1;
        }

        if (x0 != x1 && y0 != y1) {
            return -2;
        }

        if (x0 > x1) {
            return Grid_Map[x0][y0].get_Top();
        } else if (x0 < x1) {
            return Grid_Map[x0][y0].get_Down();
        } else if (y0 > y1) {
            return Grid_Map[x0][y0].get_Left();
        } else {
            return Grid_Map[x0][y0].get_Right();
        }
    }

    void add_vertical_edges(vector<vector<int>> ver_values) {
        for (int i = 0; i < Map_Length; i++) {
            for (int j = 0; j < Map_Length; j++) {
                if (i == 0) {
                    Grid_Map[i][j].set_X(i);Grid_Map[i][j].set_Y(j);
                    Grid_Map[i][j].set_Top(ver_values[i][j]);
                } else {
                    Grid_Map[i][j].set_X(i);Grid_Map[i][j].set_Y(j);
                    Grid_Map[i][j].set_Top(ver_values[i][j]);
                    Grid_Map[i - 1][j].set_Down(ver_values[i][j]);    
                }
            }
        }        
    }

    void add_Horizontal_edges(vector<vector<int>> Hor_values) {
        for (int i = 0; i < Hor_values.size(); i++) {
            for (int j = 0; j < Hor_values.size(); j++) {
                if (j == 0) {
                    Grid_Map[i][j].set_X(i);Grid_Map[i][j].set_Y(j);
                    Grid_Map[i][j].set_Left(Hor_values[i][j]);
                } else {
                    Grid_Map[i][j].set_X(i);Grid_Map[i][j].set_Y(j);
                    Grid_Map[i][j].set_Left(Hor_values[i][j]);
                    Grid_Map[i][j - 1].set_Right(Hor_values[i][j]);    
                }
            }
        }        
    }
    
};
#endif






