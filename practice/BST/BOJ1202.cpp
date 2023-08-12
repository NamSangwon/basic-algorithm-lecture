#include <bits/stdc++.h>

// 보석 도둑 (클론 코딩)

using namespace std;

int n, k;
pair<int, int> jewel[300003];
multiset<int> bag;

int main(){
    cin >> n >> k;

    // 보석의 무게와 가치를 입력받고 1. 무게 > 2. 가치 순으로 정렬
    for(int i = 0; i < n; i++) cin >> jewel[i].second >> jewel[i].first;
    sort(jewel, jewel+n);

    // 각 가방의 최대 수용량 입력 받기
    for(int i = 0; i < k; i++){
        int bag_num;
        cin >> bag_num;
        bag.insert(bag_num);
    }

    long long result = 0;

    // 무겁고 비싼 보석부터 가방에 담기 
    for(int i = n-1; i >= 0; i--){
        int m, v;
        tie(v, m) = jewel[i]; // v = 가치 / m = 무게
        auto it = bag.lower_bound(m); // 보석의 무게 m보다 무거운 가방 중 가장 가벼운 가방
        if(it == bag.end()) continue;
        // 가방에 보석 담고 제거
        result += v;
        bag.erase(it); 
    }

    cout << result;
}