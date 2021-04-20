#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "WareHouseHash.cpp"

using namespace std;

int find_Prime(int size) {
    if (size < 5) {
        return 5;
    } else if (size < 7) {
        return 7;
    } else if (size < 11) {
         return 11;     
    } else if (size < 20 ) {
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
    } else if (size <= 600) {
        return 601;
    } else if (size <= 700) {
        return 701;
    } else if (size < 800) {
        return 809;
    } else if (size < 900) {
        return 907;
    } else if (size < 1000) {
        return 1009;
    } else if (size <= 1500) {
        return 1511;
    } else if (size <= 1600) {
        return 1601; 
    } else if (size <= 1900) {
        return 1901;
    } else if (size <= 2000) {
        return 2003 ;
    } else if (size <= 2500) {
        return 2503;
    } else if (size <= 3000) {
        return 3001;
    } else if (size < 4000) {
        return 4001;
    } else if (size <= 5000) {
        return 5003;
    } else {
        return 10007;
    }

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Please supply the name of the input file\n";
    } 
    else { 
		// Read input
		ifstream inFile(argv[1]);
		int sn,n;
		inFile >> n;

		vector<WareHouse> warehouses(n);
        unordered_map<int,string> name_sn_map;
        vector<int> all_sn(n); 
        string name;

		for (int i = 0; i < n; i++) {
			inFile >> name >> sn;
			warehouses[i] = WareHouse(name, 100, sn);
            name_sn_map.insert(pair<int,string>(sn,name));
            all_sn[i] = sn;
		}
		inFile.close();  		

		// Place your algorithm here
		// If you need to create a function, place the function above the main function
		// If there's a solution (i.e., solExists == True), the results of your algorithm 
		//		should be placed in variables totSalaries and selApplicants
        WareHouseHash WH(find_Prime(n), n);
        WH.Add_All(warehouses);
        WareHouse w;
        bool is_correct;
        string str_bool;
        string result = "true";
        for (int i = 0; i < all_sn.size(); i++) {
            w = WH.Search_Warehouse(all_sn[i]);
            is_correct = w.get_name().compare(name_sn_map.find(all_sn[i]) -> second) == 0;
            if (is_correct)
                str_bool = "correct";
            else {
                str_bool = "wrong";
                result = "false";
                cout << "searching '" << all_sn[i] << "' and find the'" << w.get_name() << "' and the answer should be '" << name_sn_map.find(all_sn[i]) -> second << endl ;
            }     
        }

        cout << "the tests result is " << result;
    }

    return 0;
}
