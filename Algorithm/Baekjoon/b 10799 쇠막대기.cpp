#include <cstdio>
#include <stack>
using namespace std;
char str[100001];

int main() {
	stack<int> s;
	scanf("%s", &str);
	int cnt = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '(') {
			s.push(i);
		}
		else {
			if ((i - s.top()) == 1) {
				s.pop();
				cnt += s.size();
			}
			else {
				s.pop();
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
}