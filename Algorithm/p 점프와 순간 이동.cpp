#include <iostream>
using namespace std;

int solution(int n)
{
	int ans = 1;
	while (n != 1) {
		ans += n % 2;
		n /= 2;
	}
	return ans;
}