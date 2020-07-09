#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> num;
    vector<int> tmp;
    int len = s.size() - 1;
    string tmp_num = "";
    for (int i = 2; i < len; i++) {
        if (isdigit(s[i])) {
            tmp_num += s[i];
        }
        else if (s[i] == ',') {
            tmp.push_back(stoi(tmp_num));
        }
        else {
            tmp.push_back(stoi(tmp_num));
            num.push_back(tmp);
            tmp.clear();
            tmp_num = "";
        }
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++) {
        for (int j = 0; j < num[i].size(); j++) {
            if (find(answer.begin(), answer.end(), num[i][j]) == answer.end()) {
                answer.push_back(num[i][j]);
                break;
            }
        }
    }
    return answer;
}

int main() {
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    for (auto a : solution(s)) {
        cout << a << " ";
    }
}