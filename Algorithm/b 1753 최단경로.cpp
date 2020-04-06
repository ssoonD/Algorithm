#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 20000 + 1
#define INF 987654321
using namespace std;

int v, e, k;
vector<pair<int, int>> graph[MAX];
// vector<pair<int, int>>�� ���� MAX���� ����
// graph[v]�� (u,w)�� ����

vector<int> dijkstra(int start, int vertex) {
	vector<int> distance(vertex, INF); // start�� �������� �Ÿ� 
	// INF�� �ʱ�ȭ �� vertex���� ���Ҹ� ������ vector
	distance[start] = 0; // �ڱ� �ڽſ��� ���� ��� 0

	priority_queue<pair<int, int>> pq; // cost, vertex
	pq.push(make_pair(0, start)); // �ʱ� ���� ������

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cv = pq.top().second;
		pq.pop();

		if (distance[cv] < cost)
			continue;

		for (int i = 0; i < graph[cv].size(); i++) {
			int nv = graph[cv][i].first;
			int ns = cost + graph[cv][i].second;

			if (distance[nv] > ns) {
				distance[nv] = ns;
				pq.push(make_pair(-ns, nv));
			}
		}
	}
	return distance;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> v >> e; cin >> k; v++;
	for (int i = 0; i < e; i++) {
		int vertex, u, w;
		cin >> vertex >> u >> w;
		graph[vertex].push_back(make_pair(u, w));
	}

	vector<int> answer = dijkstra(k, v);

	for (int i = 1; i < v; i++) {
		if (answer[i] == INF)
			cout << "INF\n";
		else
			cout << answer[i] << "\n";
	}
	return 0;
}