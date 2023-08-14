#include <bits/stdc++.h>

using namespace std;

// 경로 찾기

int n;
vector<int> board[101];
bool visit[101][101];
queue<int> q;

int main(){
    cin >> n;

    // 예제 입력 받기
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int possible;
            cin >> possible;
            if (!possible) continue;
            board[i].push_back(j);           
        }
    }

    for(int i = 1; i <= n; i++){
        // 시작 원소 구하기
        for(auto idx : board[i]){
            if(idx != 0) {
                q.push(idx);
                visit[i][idx] = true;
                break;
            }          
        }
        // 탐색
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : board[cur]){
                if(visit[i][nxt]) continue;
                q.push(nxt);
                visit[i][nxt] = true;
            }
        }
    }

    // 결과 출력
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << visit[i][j] << ' ';
        }
        cout << '\n';
    }
}