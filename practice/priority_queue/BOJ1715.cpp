#include <bits/stdc++.h>

using namespace std;

// 카드 정렬 (풀이 참고)

// class cmp{
//     public:
//         bool operator()(int a, int b){
//             return a > b;
//         }
// };

int n;
priority_queue<int, vector<int>, greater<int>> pq; 
// priority_queue<int, vector<int>, cmp> pq; // 클래스 구성하지 않고 greater<int> 사용 가능

int main(){
    cin >> n;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        pq.push(num);
    }

    int result = 0; // 해당 자료형이 범위를 넘어서지 않는지 항상 판단 필요!

    // 클론 코딩 (허프만 코딩 = 파일의 압축과 연관 (.rar, .zip, ...))
    while(pq.size() > 1){ 
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        result += a + b;
        pq.push(a+b);
    }

    cout << result;
}