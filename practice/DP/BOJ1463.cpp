#include <bits/stdc++.h>

// [힌트]
// 1로 만들기 (arr[1] = 0) 
// 1. X가 3으로 나누어 떨어지면, 3으로 나눈다.  => arr[k] = arr[k/3] + 1
// 2. X가 2로 나누어 떨어지면, 2로 나눈다.      => arr[k] = arr[k/2] + 1
// 3. 1을 뺀다.                               => arr[k] = arr[k-1] + 1
// # BFS로 문제를 풀 수 있음!

using namespace std;

int arr[1000001];

int main(){
    int n;
    cin >> n;

    arr[1] = 0;

    // 다음과 같이 코드를 작성하면 최소값을 구할 수 없음
    // for(int i = 2; i <= n; i++){
    //     if(i % 3 == 0) arr[i] = arr[i/3] + 1;
    //     else if (i % 2 == 0) arr[i] = arr[i/2] + 1;
    //     else arr[i] = arr[i-1] + 1;
    // }

    // {클론 코딩}
    // 우선 1로 먼저 뺸 후 1을 뺀 값과 2 또는 3으로 나눈 값을 비교하여 
    // 더 작은 횟수의 연산을 시행하는 경우를 택한다.
    for(int i = 2; i <= n; i++){
        arr[i] = arr[i-1] + 1;
        if (i % 2 == 0) arr[i] = min(arr[i], arr[i/2] + 1);
        if (i % 3 == 0) arr[i] = min(arr[i], arr[i/3] + 1);
    }

    cout << arr[n];
}