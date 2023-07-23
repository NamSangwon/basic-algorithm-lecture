#include <bits/stdc++.h>

// 부분 수열의 합 구하기 

using namespace std;

int n, s;
int cnt = 0;
int arr[21];

void func(int start, int sum);

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    func(0, 0);

    cout << cnt;
}

void func(int start, int sum){
    if(sum == s && start != 0){
        cnt++;
        return;
    }

    for(int i = start; i < n; i++){
        sum += arr[i];
        func(i+1, sum);
        sum -= arr[i];
    }
}