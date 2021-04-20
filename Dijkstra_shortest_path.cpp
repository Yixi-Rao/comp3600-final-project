#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <queue>
#include "Map.cpp"
#include "Location.cpp"


using namespace std;

struct Node {
    int X,Y;
    int distance;
    Node () {

    }
    Node (int x, int y, int d) {
        X = x; Y = y; distance = d;
    }
    bool operator < (const Node &x) const {
        return x.distance < distance;
    }
};

class Dijkstra_shortest_path {
   
private:
    int V_Num;
    Map map;
    int S_X;
    int S_Y;

public:
    Dijkstra_shortest_path(int length, Map m, int x, int y) {
        map   = m;
        V_Num = length * length;
        S_X   = x;
        S_Y   = y;
    };

    Dijkstra_shortest_path() {
        V_Num = 0;
    };

    ~Dijkstra_shortest_path() {

    };

    void dijkstra() {
        priority_queue<Node> Q;
        Node S_node(S_X, S_Y, 0);
        map.set_Map_Distance(S_X, S_Y, 0);
        map.set_Map_Parent(S_X, S_Y, S_X, S_Y);
        Q.push(S_node);
        Node U_node;

        int U_X,U_Y,E_X,E_Y;
        
        while (!Q.empty()) {
            U_node = Q.top(); Q.pop();
            U_X = U_node.X; U_Y = U_node.Y;
            
            if (map.get_Map_Visited(U_X, U_Y)) {
                continue;
            }

            map.set_Map_Visited(U_X, U_Y); 

            vector<Address> edges = map.adjacent_edges(U_X, U_Y);
            
            for (int i = 0; i < edges.size(); i++) {
                E_X = edges[i].get_X(); E_Y = edges[i].get_Y();

                if (!map.get_Map_Visited(E_X, E_Y) &&
                    map.Two_V_Distance(U_X, U_Y, E_X, E_Y) + map.get_Map_Distance(U_X, U_Y) < map.get_Map_Distance(E_X, E_Y)) {
                        
                        map.set_Map_Distance(E_X, E_Y, map.Two_V_Distance(U_X, U_Y, E_X, E_Y) + map.get_Map_Distance(U_X, U_Y));
                        Node R_Node(E_X ,E_Y, map.get_Map_Distance(E_X, E_Y));
                        Q.push(R_Node);
                        map.set_Map_Parent(E_X, E_Y, U_X, U_Y);
                    }
            }    
        }   
    }

    vector<Location> get_Path_to(int X_D, int Y_D) {
        vector<Location> result;
        result.push_back(Location(X_D, Y_D));
        int px = map.get_Map_Parent(X_D, Y_D).first; int py = map.get_Map_Parent(X_D, Y_D).second;
        while (px != S_X || py != S_Y) {
            result.push_back(Location(px, py));
            pair<int,int> p_pair = map.get_Map_Parent(px,py);
            px = p_pair.first;
            py = p_pair.second;
        }
        result.push_back(Location(S_X, S_Y));
        return result;
    }

    Map get_Finished_Map () {
        return map;
    }

    int get_V_Num () {
        return V_Num;
    }

    
};




