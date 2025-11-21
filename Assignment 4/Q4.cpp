#include <iostream>
#include <queue>

using namespace std;

void firstNonRepeatingCharacter(const string& input) {
    int freq[26] = {0};
    queue<char> q;

    for (char ch : input) {
        freq[ch - 'a']++;
        q.push(ch);
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main() {
    string input;
    getline(cin, input);
    string res = "";
    for (char ch : input) {
        if (ch != ' ') {
            res += ch;
        }
    }

    firstNonRepeatingCharacter(res);

    return 0;
}
