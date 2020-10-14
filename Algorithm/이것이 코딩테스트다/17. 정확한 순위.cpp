#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/* ���� �ڵ�
vector<int> students[501];
bool chk[501];

bool solution(int start, int n) {
	int cnt = n;
	queue<int> q;
	q.push(start);
	chk[start] = true;

	while (!q.empty()) {
		int node = q.front(); q.pop();
		// �� �� üũ
		cnt--;
		for (int i = 0; i < students[node].size(); i++) {
			int next = students[node][i];
			if (!chk[next]) {
				q.push(next);
				chk[next] = true;
			}
		}
	}

	if (cnt == 0) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int answer = 0;
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		students[u].push_back(v);
		students[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		fill(chk + 1, chk + n + 1, false);
		if (solution(i, n)) answer++;
	}

	cout << answer << '\n';
}
*/

#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����

// ����� ����(N), ������ ����(M)
int n, m;
// 2���� �迭(�׷��� ǥ��)�� �����
int graph[501][501];

int main(void) {
	cin >> n >> m;

	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	for (int i = 0; i < 501; i++) {
		fill(graph[i], graph[i] + 501, INF);
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
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
	}

	// ��ȭ�Ŀ� ���� �÷��̵� ���� �˰����� ����
	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	int result = 0;
	// �� �л��� ��ȣ�� ���� �� �� Ȯ���ϸ� ���� �������� üũ
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] != INF || graph[j][i] != INF) {
				cnt += 1;
			}
		}
		if (cnt == n) {
			result += 1;
		}
	}
	cout << result << '\n';
}

