#include <bits/stdc++.h>

using namespace std;

// 연속합 중에서 가장 큰 값 구하기 (클론 코딩)

int n;
int arr[100001];
int result[100001];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        result[i] = arr[i]; // ※
    }

    // 예제 1
    // 10 -4 3 1  5  6  -35 12 21 -1
    // 10  6 9 10 15 21 -14 12 33 32 
    for(int i = 1; i <= n; i++){
        result[i] = max(result[i], result[i-1] + arr[i]);
    }
    
    cout << *max_element(result+1, result+n+1);
}