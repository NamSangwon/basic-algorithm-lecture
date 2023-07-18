#include <bits/stdc++.h>

using namespace std;

// BFS 기초 - 미로 탐색
// 배열을 문자열로 입력 받음 -> 항상 문제 풀 시 입력 값 확인!

string board[102] = {};
int visit[102][102] = {};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int N, M;
    int distance = 1;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
            cin >> board[i];

    visit[0][0] = distance;
    queue<pair<int,int>> q;
    q.push({0, 0});
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int dir=0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] != '1' || visit[nx][ny] > 0) continue;
            visit[nx][ny] = distance;
            q.push({nx,ny});
        }
        distance++;
    }
    
    cout << visit[N-1][M-1];
}
