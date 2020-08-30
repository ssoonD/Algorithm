#include<string>
#include<vector>
using namespace std;

int fb[100010];

int solution(int n)
{
    fb[0] = 0;
    fb[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fb[i] = fb[i - 1] + fb[i - 2];
        fb[i] %= 1234567;
    }
    return fb[n];
}