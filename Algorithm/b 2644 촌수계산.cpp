#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;
#define MAX 100 + 1
vector<int> family[MAX];
int check[MAX];

int solution(int p1, int p2) {
    memset(check, -1, sizeof(check));
    queue<int> q;
    check[p1] = 0;
    int cnt = 0;
    q.push(p1);
    while (!q.empty()) {
        int node = q.front();
        cnt = check[node] + 1;
        q.pop();
        if (node == p2) {
            return check[node];
        }
        for (int i = 0; i <family[node].size(); i++) {
            int next = family[node][i];
            if (check[next] < 0) {
                check[next] = cnt;
                q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int p1, p2; cin >> p1 >> p2;
    int m; cin >> m;
    while (m--) {
        int parents, child; 
        cin >> parents >> child;
        family[child].push_back(parents);
        family[parents].push_back(child);
    }
    cout << solution(p1, p2) << "\n";
    return 0;
}