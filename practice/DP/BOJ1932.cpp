#include <bits/stdc++.h>

// 정수 삼각형의 경로 최대값 구하기 (오답 수정)

using namespace std;

int n;
int tri[501][501];
// int arr[501];
int arr[501][501];

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> tri[i][j];

    arr[1][1] = tri[1][1];

    // 다음은 다음 층의 대각선 중 큰 수만을 선택한다.
    // 다움과 같은 방식은 최대가 되는 경로라는 것을 보장하지 않음
    // int cursor = 1;
    // for(int i = 2; i <= n; i++){
    //     arr[i] = arr[i-1] + max(tri[i][cursor], tri[i][cursor+1]);
    //     if(tri[i][cursor] < tri[i][cursor+1]) cursor++;
    // }
    // cout << arr[n];

    // (tri)  |  (arr)
    //   3    |    3
    //  2 4   |   5 7
    // 1 0 3  |  6 7 10  => 마지막 행의 최대 값이 결과
    for(int i = 2; i <= n; i++){
        for (int j = 1; j <= i; j++){
            arr[i][j] = tri[i][j] + max(arr[i-1][j-1], arr[i-1][j]);
        }
    }

    cout << *max_element(arr[n] + 1, arr[n] + n + 1); // 마지막 행에서의 최대값
}