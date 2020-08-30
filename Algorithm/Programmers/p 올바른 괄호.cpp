#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    int len = s.size();
    stack<int> tmp;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            tmp.push(0);
        }
        else {
            if (tmp.empty()) return false;
            else tmp.pop();
        }
    }
    if (tmp.empty()) return true;
    else return false;
}