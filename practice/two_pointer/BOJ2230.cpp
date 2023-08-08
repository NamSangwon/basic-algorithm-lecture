#include <bits/stdc++.h>

// 수 고르기 문제
// [투 포인터] 
// 배열에서 이중 for문을 사용하는 대신 2개의 포인터를 통해 같은 기능을 
// 단축된 시간에 해결하도록 함

using namespace std;

int n, m;
int arr[100001];

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int min_num = 0x7fffffff;

    // [정답 풀이 코드]
    int en = 0;
    for(int st = 0; st < n; st++){
        while(arr[en] - arr[st] < m) en++;
        if (en == n) break;
        min_num = min(min_num, arr[en] - arr[st]);
    }

    // [내가 짠 코드]
    // int st = 0;
    // int en = 0;
    // while(st < n && en < n){
    //     int num = arr[en] - arr[st];
    //     if (num < m){
    //         en++;
    //         continue;
    //     }
    //     else{
    //         min_num = min(min_num, num);
    //         st++;
    //     }
    // }

    cout << min_num;
}