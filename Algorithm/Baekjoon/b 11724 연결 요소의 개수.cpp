#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[1001];
bool check[1001];
int cnt = 0;

void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d %d", &v, &u);
		a[v].push_back(u);
		a[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}