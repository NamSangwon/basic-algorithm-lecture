#include <bits/stdc++.h>

// 키 순으로 줄 세우기 (풀이 참고 - 주석 부분)

using namespace std;

int n, m;
vector<int> board[32001];
int degree[32001];
queue<int> q;
vector<int> result;

int main(){
    cin >> n >> m;

    while(m--){
        int u, v;
        cin >> u >> v;
        board[u].push_back(v);
        degree[v]++;
    }

    for(int i = 1; i <= n; i++) 
        if(degree[i] == 0) q.push(i);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        result.push_back(cur); // ※
        for(auto nxt : board[cur]){
            degree[nxt]--;
            if(degree[nxt] == 0) q.push(nxt);
        }
    }

    if (result.size() != n) cout << "cycle exists\n"; // ※
    else{
        for(auto i : result) cout << i << ' ';
    }
}