#include <bits/stdc++.h>

// 1 ~ n까지 자연수 중에서 중복 없이 길이가 m인 수열 구하기 (클론 코딩)

using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void func(int k);

int main(){
    cin >> n >> m;

    func(0);
}

void func(int k){
    if(k == m){
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!isUsed[i]){
            arr[k] = i; // 수열에 해당 숫자 추가
            isUsed[i] = true; // 해당 숫자 사용 有
            func(k+1); // 수열에 추가 (k++, ++k => 사용 불가)
            isUsed[i] = false; // 수열에 사용된 숫자 사용 完
        }
    }
}