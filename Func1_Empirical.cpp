// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <utility>
// #include <time.h> 
// #include <ctime> 
// #include "OrderHeap.cpp"

// using namespace std;

// int main() {
    
//     ofstream outfile_build("G:/3600/code/FinalPrjCode-u6826541/emperical-analyse/build.txt");
//     ofstream outfile_extract("G:/3600/code/FinalPrjCode-u6826541/emperical-analyse/extract.txt");

//     for (int i = 0; i < 100; i++) {
//         string file_path = "G:/3600/code/createTxt/F1-emperaical/test_";;
//         file_path.append(to_string(i));
//         file_path.append(".txt");
//         ifstream inFile(file_path);\
//         int n;
//         inFile >> n;

//         vector<Order> All_orders(n);
//         int t;
//         for (int j = 0; j < n; j++) {
//             inFile  >> t ;
//             All_orders[j] = Order(t,"name",1,1,0);
//         }
//         inFile.close();

//         OrderHeap OH;
//         clock_t sb = clock();
//         for (int t = 0; t < All_orders.size(); t++) {
//             OH.Max_heap_Insert(All_orders[t]);
//         }
//         clock_t eb = clock();
//         outfile_build << ((double) (eb-sb)) / CLOCKS_PER_SEC << endl;

//         Order max_order;
//         clock_t se = clock();
//         max_order = OH.Heap_Extract_Max();
//         clock_t ee = clock();
//         outfile_extract << ((double) (eb-sb)) / CLOCKS_PER_SEC << endl;

//     }

//     outfile_build.close();
//     outfile_extract.close();

// }
