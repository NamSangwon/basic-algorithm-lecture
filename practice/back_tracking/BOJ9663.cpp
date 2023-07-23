#include <bits/stdc++.h>

using namespace std;

// 체스판에 퀸을 서로 공격할 수 없게 놓기 (클론 코딩)

int n;
int cnt = 0;

// 2중 배열로 처리하면 O(N^2)만큼 소비되는 시간을 O(N)으로 줄이기 위함
// row를 반복문을 통해 한칸 씩 두도록 하기 때문에 고려할 필요 X
bool column[40]; // column을 차지하고 있는지
// 각 인수는 체스판의 대각선의 위치 =? 체스판 = 4x4 -> 대각선 = 7게
bool slash[40]; // / 방향 대각선을 차지하고 있는지 
bool back_slash[40]; // \ 방향 대각선을 차지하고 있는지

//      1   2   3    4
// +---+---+---+---+
// | 1 | 2 | 3 | 4 |
// +---+---+---+---+ 5
// | 2 | 3 | 4 | 5 |
// +---+---+---+---+ 6
// | 3 | 4 | 5 | 6 |
// +---+---+---+---+ 7 
// | 4 | 5 | 6 | 7 |
// +---+---+---+---+

void queen(int k);

int main(){
    cin >> n;

    queen(0);

    cout << cnt;
}

void queen(int k){
    if(k == n){
        cnt++;
        return;
    }

    for(int i = 0; i < n; i++){ // (k, i) == (row, column)
        if(column[i] || slash[i+k] || back_slash[k-i+n-1]) continue;
        column[i] = 1;
        slash[i+k] = 1;
        back_slash[k-i+n-1] = 1;
        queen(k+1);
        column[i] = 0;
        slash[i+k] = 0;
        back_slash[k-i+n-1] = 0;
    }
}