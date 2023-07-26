#include <bits/stdc++.h>

// 감시카메라의 사각 지대의 최소값 구하기 (클론 코딩)

using namespace std;

int n, m;
int result = 0;
int board1[10][10];
int board2[10][10];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> cctv;

// 범위를 넘어 가는 지 확인하는 함수
bool check_bound(int a, int b){
    return (a < 0 || a >= n || b < 0 || b >= m);
}

// cctv에 감지되는 구역을 표시하는 함수
void seeing_cctv(int x, int y, int dir){
    dir %= 4;
    while(1){
        x += dx[dir];
        y += dy[dir];
        if(check_bound(x,y) || board2[x][y] == 6) return;
        if(board2[x][y] != 0) continue;
        board2[x][y] = 7; // cctv에 의해 감시되는 구역
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> board1[i][j];
            if (board1[i][j] > 0 && board1[i][j] < 6) cctv.push_back({i, j});
            if (board1[i][j] == 0) result++;
        }

    // 1 << (2*cctv.size()) = 2의 (2*cctv.size())승 = 4의 cctv.size()승
    for(int tmp = 0; tmp < (1<<2*cctv.size()); tmp++){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                board2[i][j] = board1[i][j];

        // 각 cctv의 4가지를 확인하기 위한 임시 변수
        // (시간적 여유가 있기 때문에 추가적인 예외를 두지 않고 
        //                          모든 cctv의 4가지를 확인한다.)
        int brute = tmp;

        // cctv의 사각지대 확인
        for(int i = 0; i < cctv.size(); i++){
            int dir = brute % 4; // n번쨰 cctv
            brute /= 4; // n+1번째 cctv
            int x = cctv[i].first;
            int y = cctv[i].second;
            if(board1[x][y] == 1){ // ─> (일방향)
                seeing_cctv(x, y, dir);
            }
            else if(board1[x][y] == 2){ // <─> (양방향 180도)
                seeing_cctv(x, y, dir);
                seeing_cctv(x, y, dir+2);
            }
            else if(board1[x][y] == 3){ // ┌ (양방향 90도)
                seeing_cctv(x, y, dir);
                seeing_cctv(x, y, dir+1);
            }
            else if(board1[x][y] == 4){ // ┴ (세방향)
                seeing_cctv(x, y, dir);
                seeing_cctv(x, y, dir+1);
                seeing_cctv(x, y, dir+2);
            }
            else if(board1[x][y] == 5){ // ┼ (네방향)
                seeing_cctv(x, y, dir);
                seeing_cctv(x, y, dir+1);
                seeing_cctv(x, y, dir+2);
                seeing_cctv(x, y, dir+3);
            }
        }

        int val = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board2[i][j] == 0) val++;
        result = min(result, val);
    }
    cout << result;
}