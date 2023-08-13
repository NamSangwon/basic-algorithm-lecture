#include <bits/stdc++.h>

using namespace std;

int n, m, st;
vector<int> board[1001];
bool visit[1001];
queue<int> q;

void bfs(int v){
    q.push(v);
    visit[v] = true;
    cout << v << ' ';
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : board[cur]){
            if(visit[nxt]) continue;
            q.push(nxt);
            visit[nxt] = true;
            cout << nxt << ' ';
        }
    }
    cout << '\n';
}

void dfs(int v){
    // if(visit[v]) return; <= 반목문에서 처리하므로 필요 X
    visit[v] = true;
    cout << v << ' ';
    for(auto nxt : board[v]){
        if(visit[nxt]) continue;
        // visit[nxt] = true; <= dfs()내로 들어가면 처리하기 떄문에 필요 X
        dfs(nxt);
    }
}

int main(){
    cin >> n >> m >> st;

    while(m--){
        int u, v;
        cin >> u >> v;
        board[u].push_back(v);
        board[v].push_back(u);
    }

    // 경로를 오름차순으로 출력하기 위해 정렬
    for(int i = 1; i <= n; i++) sort(board[i].begin(), board[i].end());

    dfs(st);
    cout << '\n';
    fill(visit+1, visit+n+1, 0); // 1-indexex 이기 때문에 +1 추가
    bfs(st);
}