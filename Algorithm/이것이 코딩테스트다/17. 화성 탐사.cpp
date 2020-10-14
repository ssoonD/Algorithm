#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

int testCase, n;
int graph[125][125], d[125][125];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main(void) {
	cin >> testCase;

	// ��ü �׽�Ʈ ���̽�(Test Case)��ŭ �ݺ�
	for (int tc = 0; tc < testCase; tc++) {
		// ����� ������ �Է¹ޱ�
		cin >> n;

		// ��ü �� ������ �Է¹ޱ�
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> graph[i][j];
			}
		}

		// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
		for (int i = 0; i < n; i++) {
			fill(d[i], d[i] + 125, INF);
		}

		int x = 0, y = 0; // ���� ��ġ�� (0, 0)
		// ���� ���� ���� ���� �ִ� ��δ� 0���� �����Ͽ�, ť�� ����
		priority_queue<pair<int, pair<int, int> > > pq;
		pq.push({ -graph[x][y], {0, 0} });
		d[x][y] = graph[x][y];

		// ���ͽ�Ʈ�� �˰����� ����
		while (!pq.empty()) {
			// ���� �ִ� �Ÿ��� ª�� ��忡 ���� ���� ������
			int dist = -pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			// ���� ��尡 �̹� ó���� ���� �ִ� ����� ����
			if (d[x][y] < dist) continue;
			// ���� ���� ����� �ٸ� ������ ������ Ȯ��
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				// ���� ������ ����� ��� ����
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				int cost = dist + graph[nx][ny];
				// ���� ��带 ���ļ�, �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
				if (cost < d[nx][ny]) {
					d[nx][ny] = cost;
					pq.push({ -cost, {nx, ny} });
				}
			}
		}
		cout << d[n - 1][n - 1] << '\n';
	}
}
