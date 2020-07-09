#include <string>
#include <vector>

using namespace std;

int getCount(int n) {
    int answer = 0;
    while (n > 0) {
        if (n % 2 != 0) answer++;
        n /= 2;
    }
    return answer;
}

int solution(int n) {
    int answer = 0;
    int cnt = getCount(n);
    int chk = 0;
    while (chk != cnt) {
        chk = getCount(++n);
    }
    answer = n;
    return answer;
}