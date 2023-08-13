#include <bits/stdc++.h>

using namespace std;

int n, m;
int result = 0;
vector<int> board[105];
bool visit[105];
queue<int> q;

void bfs(int st){
    q.push(st);
    visit[st] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto nxt : board[cur]){
            if(visit[nxt]) continue;
            q.push(nxt);
            visit[nxt] = true;
            result++;
        }
    }
}

int main(){
    cin >> n;
    cin >> m;

    while(m--){
        int u, v;
        cin >> u >> v;
        board[u].push_back(v);
        board[v].push_back(u);
    }

    bfs(1);

    cout << result;
}