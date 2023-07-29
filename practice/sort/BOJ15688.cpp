#include <bits/stdc++.h>

// counting sort 기본 예제

using namespace std;

int arr[2000002];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[num+1000000]++;
    }

    cout << endl;

    for(int i = 0; i < 2000002; i++){
        while(arr[i]--) cout << i - 1000000 << '\n';
    }
}