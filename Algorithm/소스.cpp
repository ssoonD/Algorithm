#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int member[100005][2];
vector<int> group[100005];
bool check[100005];
int n, m;

int solution(int start) {
    int answer = 0;
    int w = 0, h = 0;
    queue<int> q;
    vector<int> xs;
    vector<int> ys;
    check[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        int x = member[node][0];
        int y = member[node][1];
        xs.push_back(x);
        ys.push_back(y);
        for (int i = 0; i < group[node].size(); i++) {
            int next = group[node][i];
            if (!check[next]) {
                check[next] = true;
                q.push(next);
            }
        }
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    w = xs[xs.size() - 1] - xs[0];
    h = ys[ys.size() - 1] - ys[0];
    answer = (w + h) * 2;
    return answer;
}

int main() {
    int answer = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> member[i][0] >> member[i][1];
    }
    while (m--) {
        int a, b; cin >> a >> b;
        if (a != b) {
            group[a].push_back(b);
            group[b].push_back(a);
        }
    }
    for (int i = 1; i <= n; i++) {
        answer = max(answer, solution(i));
    }
    cout << answer << '\n';
}