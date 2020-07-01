#include <iostream>
#include <queue>
using namespace std;
#define MAX 50 + 2
int home[MAX][MAX];
int memo[MAX][MAX];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
vector<pair<int, int>> chicken;
int n, m;

void solution(int i, int j) {
	

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> home[i][j];
			if (home[i][j] == 2) {
				home[i][j] = 0;
				chicken.push_back({ i,j });
			}
		}
	}
	int len = chicken.size();
	for (int i = 0; i < len; i++) {
		for(int i)
	}
}