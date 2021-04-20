// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <utility>
// #include <time.h> 
// #include <ctime> 
// #include "WareHouseHash.cpp"

// using namespace std;

// int find_Prime(int size) {
//     if (size < 5) {
//         return 5;
//     } else if (size < 7) {
//         return 7;
//     } else if (size < 11) {
//          return 11;     
//     } else if (size < 20 ) {
//         return 23;
//     } else if (size < 50) {
//         return 53;
//     } else if (size < 70) {
//         return 71;
//     } else if (size < 100) {
//         return 101;
//     } else if (size < 150) {
//         return 151;
//     } else if (size < 170) {
//         return 173;
//     } else if (size < 200) {
//         return 211;
//     } else if (size < 240) {
//         return 241;
//     } else if (size < 280) {
//         return 281;
//     } else if (size < 320) {
//         return 331;
//     } else if (size < 400) {
//         return 401;
//     } else if (size < 500) {
//         return 509;
//     } else if (size <= 600) {
//         return 601;
//     } else if (size <= 700) {
//         return 701;
//     } else if (size < 800) {
//         return 809;
//     } else if (size < 900) {
//         return 907;
//     } else if (size < 1000) {
//         return 1009;
//     } else if (size <= 1500) {
//         return 1511;
//     } else if (size <= 1600) {
//         return 1601; 
//     } else if (size <= 2000) {
//         return 2003 ;
//     } else if (size <= 2500) {
//         return 2503;
//     } else if (size <= 3000) {
//         return 3001;
//     } else if (size < 4000) {
//         return 4001;
//     } else if (size <= 5000) {
//         return 5003; 
//     } else if (size < 10000) {
//         return 10007;
//     } else {
//         return 291143;
//     }

// }

// int main() {
    
//     ofstream outfile_Table("G:/3600/code/FinalPrjCode-u6826541/emperical-analyse/hashTable.txt");
//     ofstream outfile_search("G:/3600/code/FinalPrjCode-u6826541/emperical-analyse/search_hash.txt");

//     for (int i = 0; i < 100; i++) {
//         string file_path = "G:/3600/code/createTxt/F2-emperaical/test_";;
//         file_path.append(to_string(i));
//         file_path.append(".txt");
//         ifstream inFile(file_path);

//         int sn,n;
//         inFile >> n;

//         vector<WareHouse> warehouses(n);
//         string name;

// 		for (int i = 0; i < n; i++) {
// 			inFile >> name >> sn;
// 			warehouses[i] = WareHouse(name, 100, sn);
// 		}
// 		inFile.close();  

//         WareHouseHash WH(find_Prime(n), n);
        
//         clock_t sh = clock();
//         WH.Add_All(warehouses);
//         clock_t eh = clock();
//         outfile_Table << ((double) (eh-sh)) / CLOCKS_PER_SEC << endl;

//         clock_t ss = clock();
//         for (int i = 0; i < 200000; i++) {
//             WareHouse w = WH.Search_Warehouse(0); 
//         }
//         clock_t es = clock();
//         outfile_search << ((double) (es-ss)) / CLOCKS_PER_SEC << endl;
//     }
//     outfile_Table.close();
//     outfile_search.close();
// }
