#include <bits/stdc++.h>

using namespace std;

// BFS 기본 문제 - 양배추를 위한 양배추를 지키는 벌레의 최소 마리 구하기

int board[52][52];
bool visit[52][52] ;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int,int>> q;

int main(){
    int T, M, N, K; 
    cin >> T;

    while(T--){
        cin >> M >> N >> K;
        
        while(K--){
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        int bug = 0;

        for(int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (board[i][j] == 1 && !visit[i][j]){
                    visit[i][j] = true;
                    q.push({i, j});
                    while(!q.empty()){ // <-- 빠뜨림 (주의!)
                        // ==================== <-- 순서 잘못 넣음 (기존에 for문에...)
                        auto cur = q.front();
                        q.pop();
                        // ===================
                        for (int dir = 0; dir < 4; dir++){
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];
                            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                            if (board[nx][ny] == 0 || visit[nx][ny]) continue;
                            visit[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                    bug++;
                }
            }
        }
        cout << bug << "\n";

        // 테스트 여러변 할 경우 이전 보드 초기화 (빠뜨림)
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                board[i][j] = 0;
                visit[i][j] = false;
            }
        }
    }

    return 0;
}