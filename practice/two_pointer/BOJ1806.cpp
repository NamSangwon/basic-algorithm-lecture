#include <bits/stdc++.h>

// 부분 합 구하기

using namespace std;

int n, s;
int arr[100001];

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int diff = 0;
    int result = 0xffffff;
    
    for(int st = 0; st < n; st++){
        int en = st + 1;
        diff += arr[st];
        while(en < n && diff < s) diff += arr[en++];
        if(en >= n) break;
        result = min(result, en - st);
        diff = 0;
    }
    if (result == 0xffffffff) result = 0;

    cout << result;
}