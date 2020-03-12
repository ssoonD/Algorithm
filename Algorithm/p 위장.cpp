#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
	vector<pair<string, int>> tmp;
	int answer = 0;
	int len = clothes.size();
	string first, second;
	for (int i = 0; i < len; i++) {
		first = clothes[i][0];
		second = clothes[i][1];
		if (tmp[second] == 0) {

		}
	}
	return answer;
}

int main() {
	vector<vector<string>> clothes = { {"yellow_hat","headgear"},{"blue_sunglasses","eyewear"},{"green_turban","headgear"} };
	cout << solution(clothes) << '\n';
}