#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> s1;  
    string peren = "[{((){})}]";  

    cout << "Parenthesis combination is: " << peren << endl;

    bool balanced = true;

    for (int i = 0; i < peren.length(); i++) {
        if (peren[i] == '[' || peren[i] == '(' || peren[i] == '{') {
            s1.push(peren[i]);
        }
        else {
            if (s1.empty()) {  
                balanced = false;
                break;
            }
            if (peren[i] == ')' && s1.top() == '(') {
                s1.pop();
            }
            else if (peren[i] == '}' && s1.top() == '{') {
                s1.pop();
            }
            else if (peren[i] == ']' && s1.top() == '[') {
                s1.pop();
            }
            else { 
                balanced = false;
                break;
            }
        }
    }

    if (balanced && s1.empty()) {
        cout << "Balanced" << endl;
    }
    else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}