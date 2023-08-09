#include <bits/stdc++.h>

// 회사에 남아 있는 사람 확인 
// [예제 출력과 같이 출력 하기 위해 벡터에 담아 정렬 후 출력]
using namespace std;

int n;

int main(){
    unordered_set<string> h;
    string name, status;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> name >> status;
        if(status == "enter") h.insert(name);
        else h.erase(name);
    }

    // 예제 출력과 같이 출력하기 위해 벡터에 담기!
    vector<string> v(h.begin(), h.end());
    sort(v.begin(), v.end(), greater<string>()); // 벡터를 알파벳 순으로 정렬
    
    for(auto c : v) cout << c << '\n';
}