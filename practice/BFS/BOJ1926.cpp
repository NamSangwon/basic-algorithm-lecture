#include <bits/stdc++.h>

using namespace std;

// BFS 기초 (정답 풀이 클론 코딩함)

int picture[501][501] = {};
bool valid[501][501] = {};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    int n, m;
    int cnt = 0, max_area = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> picture[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // 그림이 그려져 있지 않다면 스킵
            if (picture[i][j] == 0 || valid[i][j]) continue; 
            cnt++; // 그림 개수 카운트
            queue<pair<int, int>> q;
            valid[i][j] = 1; // BFS 준비
            q.push({i, j});
            int area = 0; // 그림 크기
            while(!q.empty()){
                area++;
                pair<int, int> current = q.front();
                q.pop();
                for (int dir = 0; dir < 4; dir++){
                    int nx = current.first + dx[dir];
                    int ny = current.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; //범위를 넘어서면 스킵
                    if (valid[nx][ny] || picture[nx][ny] != 1) continue; // 이미 확인하였거나 그림이 그려저 있지 않으면 스킵
                    valid[nx][ny] = 1;
                    q.push({nx,ny}); 
                }
            }
            max_area = max(max_area, area);
        }
    }

    cout << cnt << "\n" << max_area;
}