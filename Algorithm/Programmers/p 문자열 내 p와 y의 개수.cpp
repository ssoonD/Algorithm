#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int cnt = 0;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] == 'p' || s[i] == 'P') cnt++;
        if (s[i] == 'y' || s[i] == 'Y') cnt--;
    }
    if (cnt != 0) answer = false;
    return answer;
}

int main() {
    string s = "pP000yY";
    cout << solution(s);
}