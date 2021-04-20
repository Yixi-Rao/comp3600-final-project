#include "Address.cpp"
#include "Map.cpp"
#include "Order.cpp"
#include "OrderHeap.cpp"
#include "WareHouse.cpp"
#include "WarehouseHash.cpp"
#include "Location.cpp"
#include "Dijkstra_shortest_path.cpp"

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

unordered_map<string, int> Name_SN_Map;
static vector<vector<Dijkstra_shortest_path>> Dijkstra_Maps;
static OrderHeap order_heap;

int Ask_for_MapLength() {
    int Map_length;
    cout << endl;
    cout << "===============================================Map==================================================" << endl;
    cout << endl;
    cout << "Please type the Map length (int)" << endl; cout << "=>> ";
    cin >> Map_length;
    cout << "                                          Loading Map..." << endl;
    return Map_length;
}

vector<WareHouse> Ask_For_Manufacturers(int map_length) {
    vector<WareHouse> Manufacturers_List;
    string name;
    int dispatcher = 0;
    int x,y;
    cout << endl;
    cout << "==========================================Manufacturers==============================================" << endl;
    cout << endl;
    while (name.compare("quit") != 0) {
        cout << "Type the Manufacturers' name in this city (type 'quit' to finish)" << endl; cout << "=>> ";
        cin >> name;
        if (name.compare("quit") == 0) {
            cout << "Manufacturer initialization is done!" << endl;
            break;
        }
        cout << "Manufacturer " << name << "'s location X {x <= " << map_length << "} is " << endl; cout << "=>> ";
        cin >> x;
        cout << "Manufacturer " << name << "'s location Y {y <= " << map_length << "} is " << endl; cout << "=>> ";
        cin >> y;
        cout << "_________________________________________________________" << endl;
        Name_SN_Map.insert(pair<string,int>(name,dispatcher));
        Manufacturers_List.push_back(WareHouse(name,x,y,map_length,dispatcher));
        dispatcher ++;      
    }  
    cout << "                                Manufacturers is initialized!" << endl;
    cout << endl;
    cout << "=============================================Orders===================================================" << endl;
    cout << endl;
    return Manufacturers_List;
}

Order Create_Order(string name, int x, int y, int timestamp, int sn) {
    Order result(timestamp, name, x, y, sn);
    return result;
}

OrderHeap Ask_For_OrderHeap() {

    OrderHeap Order_List;
    int TimeStamp = 0;
    int x,y,sn;   
    string name;

    cout << "Type the Order for today (type 'quit' to finish)" << endl;
    while (name.compare("quit") != 0) {
        cout << "(Order " << TimeStamp + 1 << ") First type the product name: " << endl; cout << "=>> ";
        cin >> name;
        if (name.compare("quit") == 0) {
            cout << "order Heap initialization is done!" << endl;
            break;
        }
        if( Name_SN_Map.find(name) != Name_SN_Map.end())
           sn = Name_SN_Map.find(name)-> second ;
        else
            cout<<"ERROR : the name you typed is wrong, cannot find the '" << name << "' in database!" << endl;
        cout << "(Order " << TimeStamp + 1 << ") Second type the locaiton X: " << endl; cout << "=>> ";
        cin >> x;
        cout << "(Order " << TimeStamp + 1 << ") Second type the locaiton Y: " << endl; cout << "=>> ";
        cin >> y;
        cout << "____________________________________" << endl;
        Order o = Create_Order(name, x, y, TimeStamp, sn);
        cout << name << sn << endl;
        Order_List.Max_heap_Insert(o);
        TimeStamp ++;
    }
    cout << "All orders are initialized!" << endl;
    return Order_List;
}

int find_Prime(int size) {
    if (size < 20 ) {
        return 23;
    } else if (size < 50) {
        return 53;
    } else if (size < 70) {
        return 71;
    } else if (size < 100) {
        return 101;
    } else if (size < 150) {
        return 151;
    } else if (size < 170) {
        return 173;
    } else if (size < 200) {
        return 211;
    } else if (size < 240) {
        return 241;
    } else if (size < 280) {
        return 281;
    } else if (size < 320) {
        return 331;
    } else if (size < 400) {
        return 401;
    } else if (size < 500) {
        return 509;
    } else if (size < 600) {
        return 607;
    } else if (size < 700) {
        return 701;
    } else if (size < 800) {
        return 809;
    } else if (size < 900) {
        return 907;
    } else if (size < 1000) {
        return 1009;
    } else if (size < 1500) {
        return 1511;
    } else if (size < 2000) {
        return 2003 ;
    } else if (size < 2500) {
        return 2503;
    } else if (size < 3000) {
        return 3001;
    } else if (size < 4000) {
        return 4001;
    } else if (size <= 5000) {
        return 5003;
    } else {
        return 10007;
    }

}

Order functionality_1(OrderHeap OH) {
    Order result = OH.Heap_Extract_Max();
    order_heap = OH;
    return result;
}

Location functionality_2(WareHouseHash table,int sn) {
    return table.Search_Warehouse(sn).get_location();
}

Dijkstra_shortest_path functionality_3(Location warehouse_L, Map m) {
    Dijkstra_shortest_path result_map(m.get_Map_size(), m, warehouse_L.get_X(), warehouse_L.get_Y());
    result_map.dijkstra();
    return result_map;
}

void Delivery_Order_With_Path (WareHouseHash table, OrderHeap OH, Map m) {
    cout << "                                Will display the path to the customer location" << endl;
    Order                  An_Order           = functionality_1(OH);
    Location               warehouse_location = functionality_2(table, An_Order.get_SN());
    vector<Location>       path; 
    cout << "                                                      ORDER " << An_Order.get_Time() + 1 << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;
    cout << "product name :" << An_Order.get_Product() << endl;
    cout << "product SN :" << An_Order.get_SN() << endl;
    cout << "order time :" << An_Order.get_Time() << endl;
    cout << "order location: (" << An_Order.get_location().get_X() << "," << An_Order.get_location().get_Y() << ")" << endl;
    cout << "Warehouse location: (" << warehouse_location.get_X() << "," << warehouse_location.get_Y() << ")" << endl;
    if (Dijkstra_Maps[warehouse_location.get_X()][warehouse_location.get_Y()].get_V_Num() != 0) {
        path = Dijkstra_Maps[warehouse_location.get_X()][warehouse_location.get_Y()].get_Path_to(An_Order.get_location().get_X(), An_Order.get_location().get_Y());
    } else {
        Dijkstra_shortest_path Dij_map                                        = functionality_3(warehouse_location,m);
        path                                                                  = Dij_map.get_Path_to(An_Order.get_location().get_X(), An_Order.get_location().get_Y());
        Dijkstra_Maps[warehouse_location.get_X()][warehouse_location.get_Y()] = Dij_map;
    }
    cout << "_______________________________________________________Path___________________________________________________________" << endl;
    cout << "D <- " ;
    for (int i = 0; i < path.size(); i++) {
        cout << "(" << path[i].get_X() << "," << path[i].get_Y() << ") <- " ;
    }
    cout << " S " << endl;
    cout << "__________________________________________________Can start to go!____________________________________________________" << endl; cout << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

int main() {
/* -----------------create map-----------------------------------------------------------------------------------*/
    Map X_City_Map(Ask_for_MapLength());
    Dijkstra_Maps.resize(X_City_Map.get_Map_size());
    for (int i = 0; i < Dijkstra_Maps.size(); i++) {
        vector<Dijkstra_shortest_path> ms(Dijkstra_Maps.size(), Dijkstra_shortest_path());
        Dijkstra_Maps[i] = ms;
    }
    X_City_Map.create_random_Map();
    cout << "                                       Map is initialized" << endl;
    
/* -----------------create all manufacters and all orders-----------------------------------------------------------------------------------*/
    vector<WareHouse> Manufacturers_List = Ask_For_Manufacturers(X_City_Map.get_Map_size());

    OrderHeap Order_List = Ask_For_OrderHeap();
    order_heap = Order_List;

    int p = find_Prime(Manufacturers_List.size());

    WareHouseHash Hash_Table(p, Manufacturers_List.size());
    Hash_Table.Add_All(Manufacturers_List);
    cout << "                               ----Hash Table is initialized----" << endl;
/* -----------------handle an order-----------------------------------------------------------------------------------*/
    cout << endl;
    cout << "====================================================================================================" << endl;
    cout << "|      Now you can extract an order, find the warehouse location, find the shortest path by        |" << endl;
    cout << "|      using the command 'handle' to handle an order or use command 'quit' to quit the system      |" << endl;
    cout << "|      or using the command 'search_sn' to search the serial number of a specific product name.    |" << endl;
    cout << "====================================================================================================" << endl;
    cout << endl;
    string command = "handle an order";
    while (command.compare("quit") != 0) {
        cout << "Please type the next command: " << endl; cout << "=>> ";
        cin >> command;
        
        if (command.compare("handle") == 0) {
            cout << "handing..." << endl;
            Delivery_Order_With_Path(Hash_Table, order_heap, X_City_Map);
        } else if (command.compare("search_sn") == 0) {
            string name;
            cout << "Name: " ;
            cin >> name;
            if (Name_SN_Map.find(name) != Name_SN_Map.end())
                cout << "-> mapped SN: " << Name_SN_Map.find(name)-> second << endl;
            else
                cout<<"ERROR : the name you typed is wrong, cannot find the '" << name << "' in database!" << endl;
        }
    }
    cout << "All the orders are finished!" << endl;

}