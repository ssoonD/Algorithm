#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() > 1) {
		int first, second;
		first = q.front();
		q.pop();
		second = q.front();
		q.pop();
		q.push(second);
		cout << first << " ";
	}
	cout << q.front() << '\n';
}