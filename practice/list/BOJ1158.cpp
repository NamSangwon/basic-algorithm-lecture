#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, K;
    vector<int> v;
    vector<int> answer;

    cin >> N >> K;

    for (int i = 1; i <= N; i++) v.push_back(i);

    // 구현 알고리즘 오답
    for (int i = 0; answer.size() < N; i++){ // 정답을 모두 구할 때까지 반복
        if (i % k == k-1) answer.push_back(v[i]); // 제거될 인덱스
        else v.push_back(v[i]) // 제거되지 않을 인덱스 뒤에 추가
    }

    cout << '<';
    for (auto i : answer) cout << i;
    cout << '>';
}