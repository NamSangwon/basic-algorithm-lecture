#include <bits/stdc++.h>

// 서브 트리의 노드 개수 구하기

using namespace std;

int n, r, q;
int ans = 0;
vector<int> board[100001];
int parent[100001];

void dfs(int cur){
    ans++;
    for(auto nxt : board[cur]){
        if(parent[cur] == nxt) continue;
        parent[nxt] = cur;
        dfs(nxt);
    }
}

int main(){
    cin >> n >> r >> q;

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        board[u].push_back(v);
        board[v].push_back(u);
    }

    dfs(r);
    ans = 0;

    while(q--){
        int num;
        cin >> num;
        dfs(num);
        cout << ans << '\n';
        ans = 0;
    }
}