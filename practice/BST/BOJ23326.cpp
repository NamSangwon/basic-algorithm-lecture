#include <bits/stdc++.h>

// 투어리스트 (풀이 참고)

using namespace std;

int n, q;
set<int> place; // 명소가 중복되지 않기 때문에 set 사용

int main(){
    cin >> n >> q;

    // 명소로 지정된 위치를 BST에 추가 (명소 인덱스 = 1, 2, ...) (힌트)
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if(num != 0) place.insert(i); 
    }

    int cur = 1;

    while(q--){
        int ir;
        cin >> ir;
        switch(ir){
            case 1:
                int idx;
                cin >> idx;
                if(place.find(idx) == place.end()) place.insert(idx);
                else place.erase(idx);
                break;
            case 2:
                int move;
                cin >> move;
                // cur = (cur + move) % n;
                cur = (cur + move - 1) % n + 1; // ※ 위치 이동
                break;
        
            case 3:
                if (place.empty()) cout << -1 << '\n'; // ※ 효율 상승을 위해 위치 이동 -> 불필요한 연산 하지 않도록 함
                else{
                    auto it = place.lower_bound(cur);
                    // if (*it >= cur) cout << *it - cur << '\n';
                    // else cout << n - (cur - *it) << '\n';                         // it != 최소 거리의 위치
                    if (it == place.end()) cout << n - cur + *place.begin() << '\n'; // ※ *place.begin() == 최소 거리의 위치
                    else cout << *it - cur << '\n';
                }
                break;
        }
    }
}