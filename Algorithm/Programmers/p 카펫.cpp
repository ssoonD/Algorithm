#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int tmp = brown / 2;
    for (int i = 2; i <= tmp / 2; i++) {
        int a = i;
        int b = tmp - i;
        if ((a - 1) * (b - 1) == yellow) {
            answer.push_back(b);
            answer.push_back(a);
            break;
        }
    }
    return answer;
}

