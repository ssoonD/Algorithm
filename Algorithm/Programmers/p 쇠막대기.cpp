#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    int aSize = arrangement.size();
    stack<int> s;
    for (int i = 0; i < aSize; i++) {
        if (arrangement[i] == '(') {
            s.push(i);
        }
        else {
            if (s.top() == i - 1) {
                s.pop();
                answer += s.size();
            }
            else {
                s.pop();
                answer++;
            }
        }
    }
    return answer;
}

int main() {
    string a = "()(((()())(())()))(())";
    cout << solution(a) << '\n';
}