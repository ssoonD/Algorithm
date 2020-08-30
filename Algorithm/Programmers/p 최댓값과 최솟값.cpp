#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> numbers;
    stringstream ss(s);
    string tmp;
    while (ss >> tmp) {
        numbers.push_back(stoi(tmp));
    }
    sort(numbers.begin(), numbers.end());
    answer = to_string(numbers[0]) + ' ' + to_string(numbers[numbers.size() - 1]);
    return answer;
}

int main() {
    string s = "-1 -2 -3 4";
    cout << solution(s);
}