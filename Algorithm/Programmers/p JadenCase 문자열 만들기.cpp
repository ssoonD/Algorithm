#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    int len = s.size();
    bool chk = true;
    for (int i = 0; i < len; i++) {
        if (chk) {
            s[i] = toupper(s[i]);
            chk = false;
        }
        else s[i] = tolower(s[i]);
        if (s[i] == ' ') chk = true;
    }
    return s;
}