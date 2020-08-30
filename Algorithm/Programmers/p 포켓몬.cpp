#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
	unordered_set<int> s(nums.begin(), nums.end());

	return min(nums.size() / 2, s.size());
}