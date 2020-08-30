#include <cstdio>
#include <vector>
using namespace std;
int a[1005];
bool check[1005];

void dfs(int node) {
	if (check[node]) return;
	check[node] = true;
	dfs(a[node]);
}

int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		int cnt = 0;
		scanf("%d", &n);
		// 입력 + 초기화
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			check[i] = false;
		}
		for (int i = 1; i <= n; i++) {
			if (check[i] == false) {
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}