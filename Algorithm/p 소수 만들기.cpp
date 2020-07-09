#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// 소수면 true 아니면 false
bool isPrime(int num) {
	if (num < 2) return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int solution(vector<int> nums) {
	int answer = 0;
	int sum = 0;
	int nSzie = nums.size();
	for (int i = 0; i < nSzie; i++) {
		for (int j = i + 1; j < nSzie; j++) {
			for (int k = j + 1; k < nSzie; k++) {
				sum = nums[i] + nums[j] + nums[k];
				if (isPrime(sum)) {
					answer++;
				}
			}
		}
	}
	return answer;
}