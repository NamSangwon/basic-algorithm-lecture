#include <bits/stdc++.h>

// 2 x n 타일 채우기 (클론 코딩)

using namespace std;

int n;
int board[1001];

int main(){
    cin >> n;
    board[1] = 1; // 2 x 1 -> 1가지
    board[2] = 2; // 2 x 2 -> 2가지

    // 2 x 3 = 3가지 = board[1] + board[2] 
    // 2 x 4 = 5가지 = board[2] + board[3]
    // board[n] = 2 x n 크기의 타일을 채우는 방법의 수를 10007로 나눈 나머지
    for(int i = 3; i <= n; i++) 
        board[i] = (board[i-1] + board[i-2]) % 10007;

    cout << board[n];
}