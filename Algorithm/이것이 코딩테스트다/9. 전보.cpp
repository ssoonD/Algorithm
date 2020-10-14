#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����

/* ���� �ڵ�
vector<pair<int,int>> city[30001];
int cost[30001];

void solution(int start, int n) {
	priority_queue<pair<int, int>> pq; // {next node,time}
	pq.push({ start,0 });
	cost[start] = 0;
	while (!pq.empty()) {
		int node = pq.top().first;
		int time = pq.top().second;
		pq.pop();
		for (int i = 0; i < city[node].size(); i++) {
			int next_node = city[node][i].first;
			int next_time = city[node][i].second + time;
			if (cost[next_node] > next_time) {
				cost[next_node] = next_time;
				pq.push({ next_node, next_time });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m, c; cin >> n >> m >> c;
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		city[x].push_back({ y,z });
	}

	fill(cost, cost + 30001, INF);
	solution(c, n);

	int count = -1, answer = 0;
	for (int i = 1; i <= n; i++) {
		if (cost[i] != INF) {
			count++;
			answer = max(answer, cost[i]);
		}
	}

	cout << count << " " << answer << '\n';
}
*/

// ����� ����(N), ������ ����(M), ���� ��� ��ȣ(Start)
int n, m, start;
// �� ��忡 ����Ǿ� �ִ� ��忡 ���� ������ ��� �迭
vector<pair<int, int> > graph[30001];
// �ִ� �Ÿ� ���̺� �����
int d[30001];

void dijkstra(int start) {
	priority_queue<pair<int, int> > pq;
	// ���� ���� ���� ���� �ִ� ��δ� 0���� �����Ͽ�, ť�� ����
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty()) { // ť�� ������� �ʴٸ�
		// ���� �ִ� �Ÿ��� ª�� ��忡 ���� ���� ������
		int dist = -pq.top().first; // ���� �������� ��� 
		int now = pq.top().second; // ���� ���
		pq.pop();
		// ���� ��尡 �̹� ó���� ���� �ִ� ����� ����
		if (d[now] < dist) continue;
		// ���� ���� ����� �ٸ� ������ ������ Ȯ��
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			// ���� ��带 ���ļ�, �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				// ���������̱� ������ -cost�� ���� �־��ش�
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main(void) {
	cin >> n >> m >> start;

	// ��� ���� ������ �Է¹ޱ�
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		// X�� ��忡�� Y�� ���� ���� ����� Z��� �ǹ�
		graph[x].push_back({ y, z });
	}

	// �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ
	fill(d, d + 30001, INF);

	// ���ͽ�Ʈ�� �˰����� ����
	dijkstra(start);

	// ������ �� �ִ� ����� ����
	int count = 0;
	// ������ �� �ִ� ��� �߿���, ���� �ָ� �ִ� ������ �ִ� �Ÿ�
	int maxDistance = 0;
	for (int i = 1; i <= n; i++) {
		// ������ �� �ִ� ����� ���
		if (d[i] != INF) {
			count += 1;
			maxDistance = max(maxDistance, d[i]);
		}
	}

	// ���� ���� �����ؾ� �ϹǷ� count - 1�� ���
	cout << count - 1 << ' ' << maxDistance << '\n';
}