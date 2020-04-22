#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 100000 + 1
pair<int, string> student[MAX];

bool cmp(pair<int, string> p1, pair<int, string> p2) {
	return p1.first < p2.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> student[i].first >> student[i].second;
	}
	stable_sort(student, student + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << student[i].first << " " << student[i].second << "\n";
	}
}