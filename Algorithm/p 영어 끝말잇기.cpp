#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 0,0 };
    set<string> s; s.insert(words[0]);
    int wSize = words.size();
    for (int i = 1; i < wSize; i++) {
        // 끝말 잇기가 맞지 않을 떄
        cout << i << " ";
        if (words[i - 1][words[i - 1].size() - 1] != words[i][0]) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        // 중복되는 것이 있을 때
        if (s.find(words[i]) == s.end()) {
            s.insert(words[i]);
        }
        else {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
    }
    return answer;
}

int main() {
    int n = 3;
    vector<string> w = { "hello","one","even","never" };
    for (auto a : solution(n, w)) {
        cout << a << " ";
    }
}