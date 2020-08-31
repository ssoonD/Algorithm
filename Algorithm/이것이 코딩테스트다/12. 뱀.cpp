#include <iostream>
#include <deque>
#include <queue>
using namespace std;
int apple[105][105];
int map[105][105];
//          �� �� �� ��
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int n;
deque<pair<int, int>> snake;
queue<pair<int, char>> snake_dir;

int solution() {
	// ���� ��ġ (x,y) ���� dir
	int x = 1, y = 1, dir = 0;
	int time = 0;

	while (1) {
		// ���� ���� �Ǵ� 
		// x�� �� ���� ���� 
		if (!snake_dir.empty() && time == snake_dir.front().first) {
			// ������ ȸ��
			if (snake_dir.front().second == 'D') {
				dir = (++dir) % 4;
			}
			// ���� ȸ��
			else {
				--dir;
				if (dir == -1) dir = 3;
			}
			// ���� �������� ����
			snake_dir.pop();
		}

		// ��ġ �̵� 
		x += dx[dir];
		y += dy[dir];

		// ���� ��ġ�� ���� ���� �ȿ� �����ϰ� map�� 0�� ����
		if (0 < x && x <= n && 0 < y && y <= n && map[x][y] == 0) {
			map[x][y] = 1;
			// �Ӹ��� �̵��߱� ������ ���� �տ� �־��ֱ� 
			snake.push_front(make_pair(x, y));
			if (apple[x][y] == 0) {
				// ����� ���� �� �� ��
				// 1. map���� ���� �����ֱ�
				// 2. snake���� ���� �����ֱ�
				int tail_x = snake.back().first;
				int tail_y = snake.back().second;
				map[tail_x][tail_y] = 0;
				snake.pop_back();
			}
			else {
				// ����� ���� �� �� ��
				// 1. ��� ��ġ ���� 
				apple[x][y] = 0;
			}
			time++;
		}
		// ���� �ȿ� ������ return time
		else return time;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// ��� ��ġ ���� 
	int k; cin >> n >> k;
	while (k--) {
		int r, c; cin >> r >> c;
		apple[r][c] = 1;
	}

	int l; cin >> l;
	// map�� ���� ���̸�ŭ �̵��� �ܻ��� 1�� ����ش� 
	// -> �ڱ� �ڽ��� ���� �ε����� ������ ������ ���� �Ǻ��ϱ� ���ؼ� 
	map[1][1] = 1;
	snake.push_back(make_pair(1, 1));

	// snake ���� ���� ����
	while (l--) {
		int num;
		char c;
		cin >> num >> c;
		snake_dir.push({ num,c });
	}

	cout << solution() + 1 << '\n';
}