#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
    int N;
    string ir;
    queue<int> q;

    cin >> N;

    while(N--){
        cin >> ir;

        if (ir == push){
            int num;
            cin >> num;
            q.push(num);
        }
        else if (ir == pop){
            if (q.empty()) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (ir == front){
            if (q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        else if (ir == back){
            if (q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
        else if (ir == size){
            cout << q.size() << "\n";
        }
        else if (ir == empty){
            cout << q.empty() << "\n";
        }
    }
}