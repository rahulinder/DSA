#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int>q;
    queue<int>temp;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);
    int originalSize = q.size();
    int i = 0;
    while (i < originalSize / 2) {
    temp.push(q.front());
    q.pop();
    i++;
    }
    i=0;
     while(i < originalSize / 2){
         q.push(temp.front());
         temp.pop();
         q.push(q.front());
         q.pop();
         i++;
     }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
   
    return 0;
}
