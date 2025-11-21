#include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue<int> q;

public:
    void push(int x) {
        int sz = q.size();
        q.push(x);

        // Move all previous elements behind the new element
        for (int i = 0; i < sz; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;  // 30
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;  // 20

    return 0;
}