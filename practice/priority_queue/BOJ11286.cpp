#include <bits/stdc++.h>

using namespace std;

// 절댓값 우선 순위 큐 (클론 코딩)
// cpp에서 sort()는 함수 priority_queue는 컨테이너이기 때문에
// sort()는 조건으로 함수를, priority_queue는 조건으로 클래스를 사용한다.

// ※ 우선 순위 큐에서 조건을 변경하고 싶으면 클래스를 구성하여 사용 (기존 = 최대 힙)
// 두 인자가 같으면 반드시 false를 반환
class cmp{
    public:
        bool operator() (int a, int b){
            if (abs(a) != abs(b)) return abs(a) > abs(b);
            return a > 0 && b < 0;
        }
};

int n;
priority_queue<int, vector<int>, cmp> pq;

int main(){
    cin >> n;

    while(n--){
        int num;
        cin >> num;
        if(num == 0) {
            // top(), pop()을 실행하기 전 반드시 empty() 유무 판단!
            if (pq.empty()) cout << 0 << '\n'; 
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(num);
    }
}