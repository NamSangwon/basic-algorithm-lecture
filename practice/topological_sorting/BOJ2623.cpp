#include <bits/stdc++.h>

// 음악 방송 순서 정하기

using namespace std;

int n, m;
vector<int> board[1001];
int degree[1001];
queue<int> q;

int main(){
    cin >> n >> m;

    while(m--){
        int k, prev, num;
        cin >> k;
        for(int i = 0; i < k; i++){
            cin >> num;
            if(i != 0) {
                board[prev].push_back(num);
                degree[num]++;
            }
            prev = num;
        }
    }

    for(int i = 1; i <= n; i++)
        if(degree[i] == 0) q.push(i);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << '\n';
        for(auto nxt : board[cur]){
            degree[nxt]--;
            if(degree[nxt] == 0) q.push(nxt);
        }
    }
}