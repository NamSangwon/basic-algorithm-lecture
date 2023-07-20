#include <bits/stdc++.h>

using namespace std;

// 화재 대피 가능 여부 (BOJ4179를 클론 코딩 함)

string board[1001];
int fire[1001][1001];
int run_exit[1001][1001];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(){
    int t, w, h;
    cin >> t;

    while(t--){
        bool escape = false;
        queue<pair<int,int>> q_fire = {};
        queue<pair<int,int>> q_move = {};

        cin >> w >> h;

        // 방문 여부 배열 0로 초기화
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                fire[i][j] = 0;
                run_exit[i][j] = 0;
            }
        }

        // 빌딩 지도 입력 받기
        for (int i = 0; i < h; i++)
            cin >> board[i];

        // 불 경로와 상근이 경로 큐에 추가
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if (board[i][j] == '*') {
                    q_fire.push({i, j});
                    fire[i][j] = 1;
                }
                else if (board[i][j] == '@') {
                    q_move.push({i, j});
                    run_exit[i][j] = 1;
                }
            }
        }

        // 불 이동 경로
        while(!q_fire.empty()){
            auto cur1 = q_fire.front();
            q_fire.pop();
            for(int dir1 = 0; dir1 < 4; dir1++){
                int nx = cur1.first + dx[dir1];
                int ny = cur1.second + dy[dir1];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue; // ( w <-> h 위치 주의!)!
                if (fire[nx][ny] >= 1 || board[nx][ny] == '#') continue;
                fire[nx][ny] = fire[cur1.first][cur1.second] + 1;
                q_fire.push({nx,ny});
            }
        }

        while(!q_move.empty() && !escape){
            auto cur2 = q_move.front();
            q_move.pop();
            for(int dir2 = 0; dir2 < 4; dir2++){
                int nx = cur2.first + dx[dir2];
                int ny = cur2.second + dy[dir2];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) { // 탈출 성공 ( w <-> h 위치 주의!)!
                    cout << run_exit[cur2.first][cur2.second]+1 << "\n"; 
                    escape = true;
                    break;
                }
                if (run_exit[nx][ny] >= 1 || board[nx][ny] == '#') continue;
                if (fire[nx][ny] != 0 && fire[nx][ny] <= run_exit[cur2.first][cur2.second] + 1) continue; // 불이 전파되었으며 이동 불가
                run_exit[nx][ny] = run_exit[cur2.first][cur2.second] + 1;
                q_move.push({nx,ny});
            }
        }

        if (!escape) cout << "IMPOSSIBLE\n";
    }
}