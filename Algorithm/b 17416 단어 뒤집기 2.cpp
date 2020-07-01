#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string input;
	getline(cin, input);
	int len = input.size();
	stack<char> s;
	queue<char> q;
	for (int i = 0; i < len; i++) {
		if (input[i] == '<') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			while (input[i] != '>') {
				q.push(input[i]);
				i++;
			}
			q.push(input[i]);
			while (!q.empty()) {
				cout << q.front();
				q.pop();
			}
		}
		else if(input[i]==' '){
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << " ";
		}
		else {
			s.push(input[i]);
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}