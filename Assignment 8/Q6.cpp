
#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap; 
    
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] > heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else break;
        }
    }

    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

public:
  
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    
    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

    bool empty() {
        return heap.empty();
    }
    void increase_key(int x, int k){
        int parent= ciel(x/2)-1;
        if(heap[x]<k){
                swap(heap[x], k);
                while(parent>=0){
                    if(k> heap[parent]){
                        swap(heap[parent], k);
                    }
                    parent=(parent/2)-1;
                }
            }
            
        
    }
    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(50);
    pq.push(40);
    pq.push(33);
    cout << "Priority Queue: ";
    pq.display();
    cout << pq.top() << endl;
   // pq.pop();
   pq.increase_key(2, 60);
    pq.display();
   // pq.pop();
   // pq.pop();
   // pq.display();

    return 0;
}

