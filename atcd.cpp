#include <bits/stdc++.h>
using namespace std;

enum State {q0, q1, q2, q3};

bool accept(string input) {
    stack<char> stk;
    State state = q0;
    for (char c : input) {
        switch (state) {
            case q0:
                if (c == 'C')
                    state = q2;
                else {
                    state = q1;
                    stk.push(c);
                }
                break;
            case q1:
                if (c == 'C')
                    state = q2;
                else
                    stk.push(c);
                break;
            case q2:
                if (!stk.empty() && stk.top() == 'X')
                    stk.pop();
                else
                    return false;
                state = q3;
                break;
            case q3:
                break;
        }
    }
    return state == q0 && stk.empty();
}

int main() {
	string input;
    cout << "Enter the input string: ";
    getline(cin, input);
    if (accept(input))
}
    
