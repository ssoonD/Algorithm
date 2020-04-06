#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> people;

vector<int> solution(int n) {
	vector<int> answer;
	for (int i = 0; i < n; i++) {
		int w = people[i].first;
		int h = people[i].second;
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			int nw = people[j].first;
			int nh = people[j].second;
			if (w < nw && h < nh) {
				cnt++;
			}
		}
		answer.push_back(cnt);
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int w, h; cin >> w >> h;
		people.push_back(make_pair(w, h));
	}
	for (auto a : solution(n)) {
		cout << a << " ";
	}
	cout << "\n";
}