#include <bits/stdc++.h>

// 구슬 찾기 (클론 코딩)
// [힌트] 1. 무거운 구슬과 가벼운 구슬을 따로 구별
//        2. 구슬 i보다 가벼운(무거운) 구슬 수가 전체 구슬 개수의 절반을 넘으면
//           구슬 i는 전체 구슬 중에서 무게 순으로 중간에 위치할 수 없다.

using namespace std;

int n, m;
vector<int> heavy[101], light[101];
bool visit[101];

// 힌트 2를 수행하기 위한 함수 ()
bool solve(int st, vector<int> (&board)[]){
    fill(visit, visit+n, 0); // 다수 실행하므로 visit[] 초기화 필요
    queue<int> q;
    int cnt = 0; // 힌트 2를 판단하기 위한 변수 (보다 무겁거나 가벼운지 확인)

    q.push(st);
    visit[st] = true;
    while(!q.empty()){
        int cur = q.top();
        q.pop();
        for(auto nxt : board[cur]){
            if (visit[nxt]) continue;
            q.push(nxt);
            visit[nxt] = true;
            cnt++; // 보다 무겁거나 가벼운지 확인
        }
    }  

    // 보다 무겁거나 가벼운 구슬이 절반 이상이면 중간에 위치할 가능성 zero
    return cnt >= (n+1)/2; 
}

int main(){
    cin >> n >> m;

    while(m--){
        int u, v;
        cin >> u >> v;
        heavy[u].push_back(v);
        heavy[v].push_back(u);
    }

    int result = 0;

    for(int i = 1; i <= n; i++){
        result += (solve(i, heavy) || solve(i, light));
    }

    cout << result;
}