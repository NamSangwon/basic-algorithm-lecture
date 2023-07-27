#include <bits/stdc++.h>

// 스티커 붙이기 (클론 코딩)

using namespace std;

int n, m, k;
int r, c;
int board[42][42];
int sticker[11][11];


// 90도 회전
void turn_90(){
    int temp[12][12];
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            temp[i][j] = sticker[i][j];

    for(int i = 0; i < c; i++)
        for(int j = 0; j < r; j++)
            sticker[i][j] = temp[r-1-j][i];

    swap(r, c);
}

bool check_paste(int x, int y){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            // 스티커와 보드가 서로 중첩된다면 false를 반환
            if(board[x+i][y+j] == 1 && sticker[i][j] == 1) return false;
        }
    }

    // 서로 중첩되지 않는다면 보드에 스티커 부착
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(sticker[i][j] == 1) board[x+i][y+j] = 1;
        }
    }

    return true;
} 

int main(){
    cin >> n >> m >> k;

    while(k--){
        cin >> r >> c;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> sticker[i][j];

        for(int rotate = 0; rotate < 4; rotate++){
            bool is_paste = false; // 스티커 부착 가능 여부
            // 좌상단부터 우하단까지 스티커 부착 가능 여부 판단
            // ex. sticker = 3x3 && board = 5x5
            // (0,0) -> (0,1) -> (0,2) -> (1,0) -> ... -> (2,2)
            // 스티커의 크기 이상의 좌표는 범위를 초과하기 때문에 생략
            for(int x = 0; x <= n - r; x++){ // 
                if (is_paste) break;
                for(int y = 0; y <= m - c; y++){
                    if(check_paste(x, y)){
                        is_paste = true;
                        break;
                    }
                }
            }
            if(is_paste) break; 
            turn_90();
        }
    }
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            result += board[i][j]; // if 문 사용할 필요 X
        }
    }
    cout << result;
}