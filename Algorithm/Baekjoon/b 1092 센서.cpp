#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sensor;
vector<int> dif;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n;
	cin >> k;
	int answer = 0;
	
	while (n--) {
		int num; cin >> num;
		sensor.push_back(num);
	}
	sort(sensor.begin(), sensor.end());

	int len = sensor.size();
	for (int i = 1; i < len; i++) {
		dif.push_back(sensor[i] - sensor[i - 1]);
	}
	sort(dif.begin(), dif.end());

	for (int i = 0; i < len - k; i++) {
		answer += dif[i];
	}

	cout << answer << '\n';
}