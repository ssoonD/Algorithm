#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int bSize = baseball.size();
    for (int i = 123; i <= 987; i++) {
        int x = i / 100;
        int y = (i / 10) % 10;
        int z = i % 10;
        if (x == y || y == z || z == x) continue;
        if (x == 0 || y == 0 || z == 0) continue;

        for (int j = 0; j < bSize; j++) {
            int num = baseball[j][0];
            int strike = 0;
            int ball = 0;

            int bx = num / 100;
            int by = (num / 10) % 10;
            int bz = num % 10;
            if (bx == 0 || by == 0 || bz == 0) break;
            // strike
            if (x == bx) strike++;
            if (y == by) strike++;
            if (z == bz) strike++;
            if (strike != baseball[j][1]) break;
            // ball
            if (x == by || x == bz) ball++;
            if (y == bx || y == bz) ball++;
            if (z == bx || z == by) ball++;
            if (ball != baseball[j][2]) break;

            if (j == bSize - 1) answer++;
        }
    }
    return answer;
}

int main() {
    vector<vector<int>> b = { {123,1,1},{356,1,0},{327,2,0},{489,0,1} };
    cout << solution(b) << '\n';
}