#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

#define INF 1e9

/* ���� �ڵ�
vector<int> a[101];

int bfs(int start, int end, int n) {
	int answer = 0;
	queue<int> q;
	vector<int> cnt(n+1, -1);

	q.push(start);
	cnt[start] = 0;
	while (!q.empty()) {
		int node = q.front(); q.pop();
		if (node == end) break;
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (cnt[next] == -1) {
				cnt[next] = cnt[node] + 1;
				q.push(next);
			}
		}
	}
	return cnt[end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, x, k; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	cin >> x >> k;

	int first, second;
	first = bfs(1, k, n);
	second = bfs(k, x, n);
	if (first == -1 || second == -1) cout << -1 << '\n';
	else cout << first + second << '\n';
}
*/

// ����� ����(N), ������ ����(M)
int n, m;
// 2���� �迭(�׷��� ǥ��)�� �����
int graph[101][101];

int main(void) {
	cin >> n >> m;

	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	for (int i = 0; i < 101; i++) {
		fill(graph[i], graph[i] + 101, INF);
	}

	// �ڱ� �ڽſ��� �ڱ� �ڽ����� ���� ����� 0���� �ʱ�ȭ
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (a == b) graph[a][b] = 0;
		}
	}

	// �� ������ ���� ������ �Է� �޾�, �� ������ �ʱ�ȭ
	for (int i = 0; i < m; i++) {
		// A���� B�� ���� ����� C��� ����
		int a, b, c;
		cin >> a >> b >> c;
		// ���� ª�� ���� ������ ����
		if (c < graph[a][b]) graph[a][b] = c;
	}

	// ��ȭ�Ŀ� ���� �÷��̵� ���� �˰����� ����
	// ���ͽ�Ʈ�� : �ϳ��� ���� -> ��� ����
	// �÷��̵� ���� : ��� ���� -> ��� ����
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	// ����� ����� ���
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			// ������ �� ���� ���, 0�� ���
			if (graph[a][b] == INF) {
				cout << 0 << ' ';
			}
			// ������ �� �ִ� ��� �Ÿ��� ���
			else {
				cout << graph[a][b] << ' ';
			}
		}
		cout << '\n';
	}
}