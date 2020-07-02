#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 에라토스테네스의 체
bool chk(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i  <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;
	vector<int> num;
	int nSize = numbers.size();
	for (int i = 0; i < nSize; i++) {
		num.push_back(numbers[i] - '0');
	}
	sort(num.begin(), num.end());
	vector<int> ans;
	do {
		for (int i = 0; i <= num.size(); i++) {
			int tmp = 0;
			for (int j = 0; j < i; j++) {
				tmp = (tmp * 10) + num[j];
				ans.push_back(tmp);
			}
		}
	} while (next_permutation(num.begin(), num.end()));
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		if (chk(ans[i]))answer++;
	}
	return answer;
}

int main() {
	string n = "17";
	cout << solution(n);
}