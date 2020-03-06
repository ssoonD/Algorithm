#include <cstdio>
#include <vector>
using namespace std;

vector<int> a[20005];
int color[20005];

void dfs(int node, int c) {
	color[node] = c;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (color[next] == 0) {
			dfs(next, 3 - c);
		}
	}
}

int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		// 초기화
		for (int i = 1; i <= n; i++) {
			a[i].clear();
			color[i] = 0;
		}
		// 입력받기
		while (m--) {
			int v, u;
			scanf("%d %d", &v, &u);
			a[v].push_back(u);
			a[u].push_back(v);
		}
		for (int i = 1; i <= n; i++) {
			if (color[i] == 0) {
				dfs(i, 1);
			}
		}
		bool chk = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int next = a[i][j];
				if (color[i] == color[next]) {
					chk = false;
					break;
				}
			}
		}
		printf("%s\n", chk ? "YES" : "NO");
	}
	return 0;
}