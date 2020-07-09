#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int> > arr1, vector<vector<int> >arr2)
{
    vector<vector<int> >answer;
    answer.resize(arr1.size());
    for (int i = 0; i < answer.size(); i++) {
        answer[i].resize(arr2[0].size());
    }
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2[0].size(); j++) {
            for (int k = 0; k < arr1[0].size(); k++) {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return answer;
}

int marr1in() {
    vector<vector<int>> arr11 = { {1,4},{3,2},{4,1} };
    vector<vector<int>> arr12 = { {3,3},{3,3} };
    for (int i = 0; i < arr11.size(); i++) {
        for (int j = 0; j < arr11[0].size(); j++) {
            cout << solution(arr11, arr12)[i][j] << " ";
        }
        cout << '\n';
    }
}