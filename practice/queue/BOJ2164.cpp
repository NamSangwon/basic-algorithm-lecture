#include <bits/stdc++.h>

using namespace std;

// 직접 구현한 큐 사용 X -> 라이브러리 사용으로 오류 해결
// int arr[500002] = {};
// int front = 0;
// int back = 0;

// void push(int num){
//     arr[back++] = num;
// }
// void pop(){
//     front++;
// }
// int size(){
//     return back - front;
// }

int main(){
    int N;
    queue<int> q;

    cin >> N;

    for (int i = 1; i <= N; i++) q.push(i);

    while(q.size() != 1){
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front();
}