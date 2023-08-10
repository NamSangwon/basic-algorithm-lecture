#include <bits/stdc++.h>

// 중복되지 않게 옷을 입는 경우의 수 (클론 코딩)

using namespace std;

int t, n;

int main(){
    cin >> t;

    while(t--){
        unordered_map<string, int> h;
        cin >> n;

        while(n--){
            string type, name;
            cin >> name >> type;
            h[type] += 1;
        }

        int result = 1;
        // 모자 2개 & 안경 1개 => 3 (모자 경우의 수) * 2 (안경 경우의 수) = 6
        // item.second = item type의 개수 => map의 원소 = (item type, count) 
        for(auto item : h) result *= item.second + 1; // +1 = 착용 안하는 경우

        cout << result - 1 << '\n'; // 알몸인 경우의 수 제외
    }
}