#include <bits/stdc++.h>

// 트리의 부모 찾기 (클론 코딩)

using namespace std;

int n;
vector<int> tree[100001];
int parent[100001];

void dfs(int cur){
    for(int nxt : tree[cur]){
        if(parent[cur] == nxt) continue;
        parent[nxt] = cur;
        dfs(nxt);
    }
}

int main(){
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1);

    for(int i = 2; i <= n; i++)
        cout << parent[i] << '\n';
}