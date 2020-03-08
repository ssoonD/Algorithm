#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    for (int i = a; i <= b; i++) {
        answer += i;
    }
    return answer;
}

int main() {
    int a = 5, b = 3;
    cout << solution(a, b);
}