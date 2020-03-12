#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int n, int m) {
    if (m == 0) return n;
    else return gcd(m, n % m);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    answer.push_back(gcd(n, m));
    answer.push_back(n * m / gcd(n, m));
    return answer;
}

int main() {
    int n = 2;
    int m = 3;
    for (int i = 0; i < 2; i++) {
        cout << solution(n, m)[i] << '\n';
    }
}