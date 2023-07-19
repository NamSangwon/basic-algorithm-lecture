#include <bits/stdc++.h>

using namespace std;

int board[101][101][101] = {};
int visit[101][101][101] = {};
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<tuple<int, int, int>> q; // ※ 3개 이상의 인수는 튜플로 처리

int main(){
    int M, N, H;
    cin >> N >> M >> H;

    for(int k = 0; k < H; k++)
        for(int i = 0; i < M; i++)
            for (int j = 0; j < N; j++){
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) q.push({i, j, k}); // ※ 익은 토마토 큐에 추가
                if (board[i][j][k] == 0) visit[i][j][k] = -1; // ※ 안 익은 토마토 접근 불가로 지정
            }

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        // ============================= <--- ※ 튜플을 사용한 큐에 접근하기 위함
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        // ============================
        for(int dir = 0; dir < 6; dir++){
            int nx = curX + dx[dir]; // ※ curX <-- cur의 첫번쨰 값
            int ny = curY + dy[dir]; // ※ curY
            int nz = curZ + dz[dir]; // ※ curZ
            if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
            if (visit[nx][ny][nz] >= 0) continue; // ※ 토마토가 익은 경우 패스
            visit[nx][ny][nz] = visit[curX][curY][curZ] + 1; // ※ 일자 계산
            q.push({nx, ny, nz});
        }
    }

    for(int k = 0; k < H; k++){
        for(int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                cout << visit[i][j][k] << " ";
            }
            cout << endl;
        }
    }

    int result = 0;
    for(int k = 0; k < H; k++){
        for(int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                if(visit[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                result = max(result, visit[i][j][k]);
            }
        }
    }

    cout << result;
    return 0;
}