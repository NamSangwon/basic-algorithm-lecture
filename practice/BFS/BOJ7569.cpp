#include <bits/stdc++.h>

using namespace std;

int board[101][101][101] = {};
int visit[101][101][101] = {};
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
queue<tuple<int, int, int>> q;

int main(){
    int M, N, H;
    cin >> N >> M >> H;

    for(int k = 0; k < H; k++)
        for(int i = 0; i < M; i++)
            for (int j = 0; j < N; j++){
                cin >> board[i][j][k];
                // [토마토 익기 까지 최소 일수 등을 알기 위한 필요 조건!!] 
                // =================================================
                if (board[i][j][k] == 1) q.push({i, j, k}); // 익은 토마토 큐에 추가
                if (board[i][j][k] == 0) visit[i][j][k] = -1; // 안 익은 토마토 -1 연산
                // =================================================
            }

    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        // ============================= <--- 튜플을 사용한 큐에 접근하기 위함
        int curX, curY, curZ;
        tie(curX, curY, curZ) = cur;
        // ============================
        for(int dir = 0; dir < 6; dir++){
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            // (주의) M <-> N 오답 발생!!
            if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= H) continue;
            // [토마토 익기 까지 최소 일수 등을 알기 위한 필요 조건!!] 
            // =================================================
            if (visit[nx][ny][nz] >= 0) continue; // 방문 불가 및 이미 방문 한 곳이면 스킵
            visit[nx][ny][nz] = visit[curX][curY][curZ] + 1;
            // =================================================
            q.push({nx, ny, nz});
        }
    }

    // max()를 통해 결과 값 도출
    int result = 0;
    for(int k = 0; k < H; k++)
        for(int i = 0; i < M; i++)
            for (int j = 0; j < N; j++){
                if (visit[i][j][k] == -1){
                    cout << -1;
                    return 0;
                }
                result = max(result, visit[i][j][k]);
            }

    cout << result;
    return 0;
}