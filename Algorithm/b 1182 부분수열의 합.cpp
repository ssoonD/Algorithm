#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num[25];
int answer = 0, n, s;

// 들어가거나 안들어 가거나
// 안들어가면 : count(index+1,sum)
// 들어가면 : count(index+1,sum+num[index])
// return 문 : if(index==n)
// answer 증가 : if(sum==s)
void count(int index, int sum) {
	if (index == n) {
		if (sum == s) answer++;
		return;
	}
	count(index + 1, sum);
	count(index + 1, sum + num[index]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	count(0, 0);
	if (s == 0) answer--;
	cout << answer << '\n';
}