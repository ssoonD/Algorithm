#include <cstdio>
#include <queue>
using namespace std;

int main() {
	int n, k;
	queue<int> q;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	printf("<");
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < k - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}
	printf("%d>\n", q.front());
}