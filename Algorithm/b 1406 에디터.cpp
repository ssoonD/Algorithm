#include <cstdio>
#include <stack>
using namespace std;
char str[100001];

int main() {
	int t;
	char c;
	stack<char> left, right;
	scanf("%s", str);
	for (int i = 0; str[i]; i++) {
		left.push(str[i]);
	}
	scanf("%d", &t);
	while (t--) {
		scanf(" %c", &c);
		char word;
		if (c == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (c == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (c == 'P') {
			scanf(" %c", &word);
			left.push(word);
		}
		else {
			if (!left.empty()) {
				left.pop();
			}
		}
	}

	while(!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while(!right.empty()) {
		printf("%c", right.top());
		right.pop();
	}
}