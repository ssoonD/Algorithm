#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    bool chk = false;
    int len = arr.size();
    for (int i = 0; i < len; i++) {
        if (arr[i] % divisor == 0) {
            answer.push_back(arr[i]);
            chk = true;
        }
    }
    if (!chk) {
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    vector<int> arr = { 5,9,7,10 };
    int divisor = 5;
    for (int i = 0; i < solution(arr,divisor).size(); i++) {
        cout << solution(arr, divisor)[i] << '\n';
    }
}