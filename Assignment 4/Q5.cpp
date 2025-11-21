#include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        // Move all elements except last to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Pop the last element (stack behavior)
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        // Move elements to q2 and remember last
        int topElement;
        while (!q1.empty()) {
            topElement = q1.front();
            q2.push(topElement);
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);

        return topElement;
    }

    bool empty() {
        return q1.empty();
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