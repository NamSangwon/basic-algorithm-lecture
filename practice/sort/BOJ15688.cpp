#include <bits/stdc++.h>

// counting sort 기본 예제

using namespace std;

int arr[1000002];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[num]++;
    }

    cout << endl;

    for(int i = 0; i < 1000000; i++){
        while(arr[i]--) cout << i << '\n';
    }
}