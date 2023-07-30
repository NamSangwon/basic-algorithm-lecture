#include <bits/stdc++.h>

// 1, 2, 3 더하기 문제 (클론 코딩)

// [점화식 세우는 팁!]
// => 값들을 채워 나가면서 규칙 찾기
// 경로 추적을 요구할 때는 배열을 추가하여 전의 경로를 저장하도록 한다.

using namespace std;

int arr[11];

int main(){
    int t;
    cin >> t;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    // arr[4] = 7 (1+1+1+1, 1+3, 2+2, 1+1+2) = 중복 허용
    // => arr[4] = arr[1] + arr[2] + arr[3]
    // => arr[i] = arr[i-1] + arr[i-2] + arr[i-3]

    while(t--){
        int n;
        cin >> n;

        for(int i = 4; i <= n; i++){
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }

        cout << arr[n] << '\n';
    }
}