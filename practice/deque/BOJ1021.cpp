#include <bits/stdc++.h>

using namespace std;

deque<int> d;

void first(){
    d.pop_front();
}
void second(){
    int tmp = d.front();
    d.pop_front();
    d.push_back(tmp);
}
void third(){
    int tmp = d.back();
    d.pop_back();
    d.push_front(tmp);
}

int main(){
    int N, M;
    int find_num;
    int result = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) d.push_back(i);

    cin >> M;

    // int idx = d.front();
    while(M--){
        cin >> find_num;

        // ======= ☆ 찾고자 하는 원소의 위치 ==========
        int idx = find(d.begin(), d.end(), find_num) - d.begin();

        while(d.front() != find_num){ // 원소 찾기
            if (idx < d.size()-idx) second(); // 좌로 밀기
            else third(); // 우로 밀기
            result++;
        }

        first(); // 찾은 원소 pop 
        // ============================================

        // 오답
        // if (find_num == d.front()) {
        //     first();
        //     M--;
        // }
        // else if (abs(find_num-idx) < (N/2)) {
        //     second();
        //     result++;
        // }
        // else if (abs(find_num-idx) > (N/2)) {
        //     third();
        //     result++;
        // }
    }

    cout << result;
}