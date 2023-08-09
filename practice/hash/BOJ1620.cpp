#include <bits/stdc++.h>

// 포켓몬 도감 순서 맞추기
// 라이브러리 사용 미숙으로 인한 클론 코딩

using namespace std;

unordered_map<string, int> str2int; // 포켓몬 이름에 따른 순서 저장
string int2str[100005]; // 포켓몬 이름 저장
int n, m;

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> int2str[i]; // 포켓몬 이름 저장
        str2int[int2str[i]] = i; // 포켓몬 이름에 따른 순서 저장
    }

    for(int i = 0; i < m; i++){
        string q;
        cin >> q;
        if(isalpha(q[0])) cout << str2int[q] << '\n';
        else cout << int2str[stoi(q)] << '\n';
    }   
}