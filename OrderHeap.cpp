
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Order.cpp"


using namespace std;

class OrderHeap {
    private:
        vector<Order> Order_heap;
        int heap_size;
    public:
        OrderHeap() {
            heap_size = 0;
            // Order_heap.resize(0);       
        };
        ~OrderHeap() {
        };


    void Max_Heapify (int i) {
        int largest = -1;
        int l = this -> get_Left_child(i);
        int r = this -> get_Right_child(i);

        if (l <= heap_size - 1 && Order_heap[l].get_Time() > Order_heap[i].get_Time()) {
            largest = l;
        } else {
            largest = i;
        }
        if (r <= heap_size - 1 && Order_heap[r].get_Time() > Order_heap[largest].get_Time()) {
            largest = r;
        }
        if (largest != i) {
            Order tmp = Order_heap[i];
            Order_heap[i] = Order_heap[largest];
            Order_heap[largest] = tmp;
            Max_Heapify(largest);
        }       
    }

    void Max_heap_Insert(Order order) {
        heap_size = heap_size + 1;

        Order tmp(-999,"Null",0,0,0);

        Order_heap.push_back(tmp);
        Heap_Increase_Key (heap_size, order);
    } 

    void Heap_Increase_Key(int index, Order key) {
        if (key.get_Time() < Order_heap[index - 1].get_Time()) {
            cout << "new key is smaller than current key: " << key.get_Time() <<endl;
            return ;
        }
        Order_heap[index - 1] = key;
        while (index > 0 && Order_heap[get_Parent(index - 1)].get_Time() < Order_heap[index - 1].get_Time()) {
            Order tmp = Order_heap[get_Parent(index - 1)];
            Order_heap[get_Parent(index - 1)] = Order_heap[index - 1];
            Order_heap[index - 1] = tmp;
            index = get_Parent(index - 1) + 1;
        }
        
    }

    Order Heap_Extract_Max() {
        if (heap_size < 1) {
            cout << "!!! heap_size < 1 !!!" << endl;
            Order o;
            return o;
        }
        Order max = Order_heap[0];
        Order_heap[0] = Order_heap[heap_size - 1];
        Order_heap.pop_back();
        heap_size = heap_size - 1;
        Max_Heapify(0);
        return max;
    }

    int get_Left_child(int index) {
        return (2 * (index + 1) - 1);
    }

    int get_Right_child(int index) {
        return (2 * (index + 1));
    }

    int get_Parent(int index) {
        return ((index - 1) / 2);
    }

    vector<Order> get_Heap () {
        return Order_heap;
    }

    int get_Size () {
        return heap_size;
    }
};



