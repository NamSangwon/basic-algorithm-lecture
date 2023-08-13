#include <bits/stdc++.h>

// 연결 요소의 개수 구하기 (클론 코딩)

using namespace std;

int n, m;
vector<int> board[1003]; // 인접리스트 형식으로 구현한 그래프
bool visit[1003]; 

int main(){
    cin >> n >> m;

    // 경로 입력 받기
    while(m--){
        int u, v;
        cin >> u >> v;
        board[u].push_back(v);
        board[v].push_back(u);
    }

    int result = 0;
    for(int i = 1; i <= n; i++){
        if(visit[i]) continue;
        result++; 
        queue<int> q;
        q.push(i);
        visit[i] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nxt : board[cur]){
                if(visit[nxt]) continue;
                q.push(nxt);
                visit[nxt] = true;
            }
        }
    }

    cout << result;
}