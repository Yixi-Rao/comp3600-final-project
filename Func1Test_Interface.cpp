#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "OrderHeap.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Please supply the name of the input file\n";
    } 
    else { 
		// Read input
		ifstream inFile(argv[1]);
		int n;
		inFile >> n;

		vector<Order> All_orders(n);
        int t,x,y; string name;

		for (int i = 0; i < n; i++) {
			inFile  >> t >> name >> x >> y;
			All_orders[i] = Order(t,name,x,y,0);
		}
		inFile.close();  		

		// Place your algorithm here
		// If you need to create a function, place the function above the main function
		// If there's a solution (i.e., solExists == True), the results of your algorithm 
		//		should be placed in variables totSalaries and selApplicants
        OrderHeap OH;
        for (int i = 0; i < All_orders.size(); i++) {
            OH.Max_heap_Insert(All_orders[i]);
        }
        Order max_order;
        vector<int> all_time;
        while (!OH.get_Heap().empty()) {
             max_order = OH.Heap_Extract_Max();
             all_time.push_back(max_order.get_Time());
             // cout << "The soonest deadline order is [name : " << max_order.get_Product() << ", Time : " << max_order.get_Time()  << ", Location : (" << max_order.get_location().get_X() << "," << max_order.get_location().get_Y() << ") ]" << endl;
        }
        string answer = "correct";
        for (int i = 0; i < all_time.size() - 1; i++) {
            if (all_time[i + 1] > all_time[i]) {
                answer = "wrong";
                break;
            }
        }
        cout << "the test result is " << answer;
    }

    return 0;
}
