#include <bits/stdc++.h>

// 같은 원소가 K개 이하로 들어 있는 최장 연속 부분 수열의 길이 구하기

using namespace std;

int n, k;
int arr[200001];
int check[200001];

int main(){
    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> arr[i];

    int result = 0;
    int st = 0;
    int en = 0;

    while(st < n && en < n){
        en = st + 1;
        check[arr[st]]++;
        while(check[arr[en]] < k) check[arr[en++]]++;
        if (en >= n || st >= n) break;
        result = max(result, en - st);
        for(int i = 0; i < n; i++) check[i] = 0;
        st = en;
    }

    cout << result;
}