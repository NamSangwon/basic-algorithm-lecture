#include <bits/stdc++.h>

using namespace std;

// stl을 사용한 정렬 (구성한 bool형 함수의 조건에 따른 정렬)

int n;
vector<string> arr; // vector을 사용하여 정렬 범위를 쉽게 조절

bool check(string& a, string & b){
    // int a_len = a.size(), b_len = b.size(); <-- 함수 접근을 줄여 시간 절약!
    if (a.size() != b.size()) return a.size() < b.size(); // 길이 순

    int a_num = 0, b_num = 0;
    for(int i = 0; i < a.size(); i++){
        if (a[i] >= '0' && a[i] <= '9') a_num += a[i];
        if (b[i] >= '0' && b[i] <= '9') b_num += b[i];
    }
    if (a_num != b_num) return a_num < b_num; // 숫자 합 순

    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) return a[i] < b[i]; // 사전 순
    }
    // return a < b; // 사전순 <- 시간 절약 
}

int main(){
    string serial_num;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> serial_num;
        arr.push_back(serial_num);
    }

    sort(arr.begin(), arr.end(), check);

    for(auto i : arr) cout << i << '\n';
}