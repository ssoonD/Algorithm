#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v;

int solution(int n) {
	long long int answer = 0;
	for (int i = 1; i <= n; i++) {
		answer += abs(i - v[i - 1]);
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	cout << solution(n) << '\n';
}