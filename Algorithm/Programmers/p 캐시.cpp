#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int cSize = cities.size();
	vector<string> cache;

	for (int i = 0; i < cSize; i++) {
		transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
		vector<string> ::iterator it = find(cache.begin(), cache.end(), cities[i]);
		if (it != cache.end()) {
			string city = *it;
			cache.erase(it);
			cache.push_back(city);
			answer++;
		}
		else {
			cache.push_back(cities[i]);
			if (cache.size() > cacheSize) {
				cache.erase(cache.begin());
			}
			answer += 5;
		}
	}
	return answer;
}