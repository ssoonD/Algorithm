#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;
// {시간, index, 0이면 들어옴 1이면 나감}
bool cmp(pair<int, pair<int, int>>& p1, pair<int, pair<int, int>>& p2) {
	if (p1.first == p2.first) return p1.second.second < p2.second.second;
	return p1.first < p2.first;
}

bool every(vector<bool> chk) {
	int len = chk.size();
	for (int i = 0; i < len; i++) {
		if (!chk[i]) return false;
	}
	return true;
}

int solution(vector<vector<int>> routes) {
	int answer = 1;
	vector<pair<int, pair<int, int>>> cars;
	vector<bool> chk(sizeof(routes), false);
	int rSize = routes.size();
	for (int i = 0; i < rSize; i++) {
		cars.push_back({ routes[i][0],{i,0} });
		cars.push_back({ routes[i][1],{i,1} });
	}
	sort(cars.begin(), cars.end(), cmp);
	for (int i = 0; i < rSize; i++) {
		if (every(chk)) break;
		if (cars[i].second.second == 0) {
			chk[cars[i].second.first] = true;
		}
		else {
			answer++;
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> r = { {-20,15},{-14,-5},{-18,-13},{-5,-3} };
	cout << solution(r) << '\n';
}