#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main() {
    cout << "Postfix is : ";
    string post = "100 200 + 2 / 5 * 7 +";
    cout << post << endl;

    stack<int> s;
    int output = 0;
    int i = 0;

    while (i < post.length()) {
        if (post[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(post[i])) {
            int num = 0;
            while (isdigit(post[i])) {
                num = num * 10 + (post[i] - '0');
                i++;
            }
            s.push(num);
        }
        else { 
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();

            if (post[i] == '+') output = op1 + op2;
            else if (post[i] == '-') output = op1 - op2;
            else if (post[i] == '*') output = op1 * op2;
            else if (post[i] == '/') output = op1 / op2;

            s.push(output);
            i++;
        }
    }

    cout << "Final Output is : " << s.top() << endl;
    return 0;
}