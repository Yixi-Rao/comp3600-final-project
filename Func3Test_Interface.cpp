#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "Dijkstra_shortest_path.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Please supply the name of the input file\n";
    } 
    else { 
		// Read input
		ifstream inFile(argv[1]);
        int n, vn, hn;
        inFile >> n;

        vector<vector<int>> ver_values(n);
        for (int i = 0; i < n; i++) {
            ver_values[i].resize(n);
        }
        vector<vector<int>> Hor_values(n);
        for (int i = 0; i < n; i++) {
            Hor_values[i].resize(n);
        }

        Map map(n);
        
        for (int i = 0; i < n; i++) {
            for (int v = 0; v < n ; v++) {
                inFile >> vn;
                ver_values[i][v] = vn;
            }
            for (int h = 0; h < n ; h++) {
                inFile >> hn;
                Hor_values[i][h] = hn;
            }
        }
        
        inFile.close();

		// Place your algorithm here
		// If you need to create a function, place the function above the main function
		// If there's a solution (i.e., solExists == True), the results of your algorithm 
		//		should be placed in variables totSalaries and selApplicants
        map.add_vertical_edges(ver_values);
        map.add_Horizontal_edges(Hor_values);

        Dijkstra_shortest_path Dij_map(n ,map, 0, 0);
        Dij_map.dijkstra();
        vector<Location> paths = Dij_map.get_Path_to(n - 1, n - 1);
        
        cout << "_______________________________________________________Path___________________________________________________________" << endl;
        cout << "D <- " ;
        for (int i = 0; i < paths.size(); i++) {
            cout << "(" << paths[i].get_X() << "," << paths[i].get_Y() << ") <- " ;
        }
        cout << " S " << endl;
        cout << "______________________________________________________________________________________________________________________" << endl;
        cout << endl;
    }

    return 0;
}
