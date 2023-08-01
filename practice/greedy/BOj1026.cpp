#include <bits/stdc++.h>

// 두 배열의 각 원소를 곱하여 최소가 되는 수 구하기
// 문제에서 b를 재배열하면 안된다고 하지만 상관 쓸 필요 X

using namespace std;

int n;
int a[61];
int b[51];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(a, a+n);
    sort(b, b+n);

    int result = 0;
    for(int i = 0; i < n; i++){
        result += a[i] * b[n - 1 - i];
    }

    cout << result;
}