#include <bits/stdc++.h>

// 최소 힙

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin >> n;

    while(n--){
        int x;
        cin >> x;

        if(x == 0){
            if(pq.empty()) cout << 0 << '\n';
            else { cout << pq.top() << '\n'; pq.pop(); }
        }
        else pq.push(x);
    }
}