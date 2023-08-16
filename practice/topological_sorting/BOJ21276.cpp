#include <bits/stdc++.h>

// 계보 복원 하기

using namespace std;

int n, m;
string name[1001];
vector<int> board[1001];
int degree[1001];
queue<int> q;

int find_idx(string str){
    for(int i = 0; i < n; i++){
        if(name[i].compare(str) == 0) return i;
    }
    return -1;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> name[i];

    sort(name, name+n);

    cin >> m;
    for(int i = 0; i < m; i++){
        string x, y;
        cin >> x >> y;

        int x_idx = find_idx(x);
        int y_idx = find_idx(y);

        board[y_idx].push_back(x_idx);
        degree[x_idx]++;
    }

    int family_cnt = 0;
    for(int i = 0; i < n; i++) 
        if(degree[i] == 0) {
            q.push(i);
            family_cnt++;
        }

    for(int i = 0; i < n; i++){
        sort(board[i].begin(), board[i].end());
        for(auto child : board[i]){
            if(degree[i] == 0 && degree[child] > 1) {
                // vector에서 값을 지우는 방법 
                // (remove는 특정 값을 찾아서 완전히 지우는 것이 아닌, 벡터의 뒤로 보내기 때문에 추가로 erase를 해줘야 한다.)
                board[i].erase(remove(board[i].begin(), board[i].end(), child), board[i].end());
                degree[child]--;
            }
        }
    }

    cout << family_cnt << '\n'; // 가문의 개수 K 

    for(int i = 0; i < n; i++)  // 각 가문의 시조들의 이름
        if(degree[i] == 0) cout << name[i] << ' ';
    cout << '\n';

    for(int i = 0; i < n; i++){ // 사람의 이름, 자식의 수, 자식들의 이름
        cout << name[i] << ' ';
        cout << board[i].size() << ' ';
        for(auto child : board[i]) cout << name[child] << ' ';
        cout << '\n';
    }
}