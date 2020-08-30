#include <iostream>
#include <vector>
using namespace std;

// map ���� 
int map[55][55];
//          �� �� �� �� 
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int n, m;
// �湮�� ĭ�� �� 
int cnt = 1;

int solution(int x, int y, int d) {
	// ���� �ȿ� ���� ���� ���� 
	if (0 < x && x < n - 1 && 0 < y && y < m - 1) {
		// �湮���� �� -1�� ���� 
		map[x][y] = -1;
		for (int i = 0; i < 4; i++) {
			// ���� �Ǻ�
			// ��(0) -> ��(3)
			// ��(3) -> ��(2)
			// ��(2) -> ��(1)
			// ��(1) -> ��(0)
			d = (d + 3) % 4;
			// (nx,ny) -> �������� ȸ���� ��ġ 
			int nx = x + dx[d];
			int ny = y + dy[d];
			// ���� ������ ���� ��
			if (map[nx][ny] == 0) {
				cnt++;
				return solution(nx, ny, d);
			}
		}
		// �� ���� ��� ���� �����̸� ����
		// ������ ��ġ ���ϱ�
		switch (d)
		{
			// ��(0)
			case 0: x++; break;
			// ��(1)
			case 1: y--; break;
			// ��(2)
			case 2: x--; break;
			// ��(3)
			case 3: y++; break;
			default:
				break;
		}
		// ������ ������ �ٴ��̸� return cnt
		if (map[x][y] == 1)
			return cnt;
		else return solution(x, y, d);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x, y, d;

	cin >> n >> m;
	cin >> x >> y >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	cout << solution(x, y, d) << '\n';
}