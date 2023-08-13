#include <bits/stdc++.h>

// n번째 큰 수 구하기

using namespace std;

int n;
priority_queue<int> pq;

int main(){
    cin >> n;

    for(int i = 0; i < n*n; i++){
        int num;
        cin >> num;
        pq.push(num);
    }

    for(int i = 1; i < n; i++) pq.pop();
    
    cout << pq.top();
}