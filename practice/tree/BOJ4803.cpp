#include <bits/stdc++.h>

// 그래프의 트리 여부 판단 (클론 코딩)

using namespace std;

int n, m, tree;
vector<int> board[501];
bool visit[501];
bool isTree;

// ★[ dfs를 통해 트리 여부 확인 ]★
// (dfs 중에 방문했던 노드에 재방문 시 트리가 아님을 확인)
// 부모 노드는 prev 인수를 통해 확인
// visit 배열을 통해 방문 여부 확인
void dfs(int cur, int prev){
    for(auto nxt : board[cur]){
        if (nxt == prev) continue; // nxt가 prev(부모 노드)일 경우 스킵
        if(visit[nxt]) { // 해당 노드에 방문한 적이 있으면 트리 X
            isTree = false;
            continue;
        }
        visit[nxt] = true;
        dfs(nxt, cur);
    }
}

int main(){
    int cnt = 1;

    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i = 1; i <= n; i++) board[i].clear();
        fill(visit, visit+n+1, 0); // 1-indexed이므로 범위 파악 주의!
        tree = 0;

        // 예제 입력 받기
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            board[u].push_back(v);
            board[v].push_back(u);
        }

        // ★ [dfs()를 통해 트리 여부 확인]
        for(int i = 1; i <= n; i++){
            if(visit[i]) continue;
            visit[i] = true;
            isTree = true;
            dfs(i, -1);
            tree += isTree;
        }

        cout << "Case " << cnt++ << ": ";
        if(tree == 0) cout << "No trees." << '\n';
        else if(tree == 1) cout << "There is one tree." << '\n';
        else cout << "A forest of " << tree << " trees." << '\n';
    }
}