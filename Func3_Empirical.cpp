// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <utility>
// #include <time.h> 
// #include <ctime> 
// #include "Dijkstra_shortest_path.cpp"

// using namespace std;


// int main() {
    
//     // ofstream outfile_dijkstra("G:/3600/code/FinalPrjCode-u6826541/emperical-analyse/dijkstra.txt");
//     ofstream outfile_shortest_path("G:/3600/code/FinalPrjCode-u6826541/emperical-analyse/shortest_path.txt");

//     // for (int i = 0; i < 100; i++) {
//     //     string file_path = "G:/3600/code/createTxt/F3-emperaical/test_";;
//     //     file_path.append(to_string(i));
//     //     file_path.append(".txt");
//     //     ifstream inFile(file_path);

//     //     int n;
//     //     inFile >> n;
//     //     Map map(n);
// 	// 	inFile.close();  
//     //     map.create_uniform_Map();
//     //     Dijkstra_shortest_path Dij_map(n ,map, 0, 0);

//     //     clock_t sd = clock();
//     //     Dij_map.dijkstra();
//     //     clock_t ed = clock();
//     //     outfile_dijkstra << ((double) (ed-sd)) / CLOCKS_PER_SEC << endl;

//     //     if (i == 99) {
//     //         for (int j = 0; j < 100; j++) {
//     //            clock_t ss = clock();
//     //            Dij_map.get_Path_to(0,j);
//     //            clock_t es = clock();
//     //            outfile_shortest_path << ((double) (es-ss)) / CLOCKS_PER_SEC << endl;
//     //         }
//     //     }
        
//     // }

//     string file_path = "G:/3600/code/createTxt/F3-emperaical/test_";;
//         file_path.append(to_string(0));
//         file_path.append(".txt");
//         ifstream inFile(file_path);

//         int n;
//         inFile >> n;
//         Map map(n);
// 		inFile.close();  
//         map.create_uniform_Map();
//         Dijkstra_shortest_path Dij_map(n ,map, 0, 0);
//         Dij_map.dijkstra();
        
//         for (int j = 0; j < 100; j++) {
//             clock_t ss = clock();
//             for (int i = 0; i < 200000; i++) {
//                 Dij_map.get_Path_to(1,j);
//             }
//             clock_t es = clock();
//             outfile_shortest_path << ((double) (es-ss)) / CLOCKS_PER_SEC << endl;
//         }

//     // outfile_dijkstra.close();
//     outfile_shortest_path.close();
// }
