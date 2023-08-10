#include <bits/stdc++.h>

// 이중 우선순위 큐 - 중복 가능하기 때문에 multiset 사용
// BST를 사용하더라도 O(lgN)에 처리 가능하기 때문에 해당 문제를 BST로 풀기 가능
// 최대값 = BST의 우하측 = *prev(bst.end()) 
// 최소값 = BST의 좌하측 = *bst.begin()
// [ bst.end()는 마지막의 다음 값(empty)을 사용하기 때문에 
//   그 이전 값을 사용하기 위해 *prev(bst.end())과 같이 사용 ]

using namespace std;

int t, n;
multiset<int> bst;

int main(){
    cin >> t;

    while(t--){
        cin >> n;

        while(n--){
            char ch;
            int num;
            cin >> ch >> num;
            if(ch == 'I') bst.insert(num);
            else {
                if(bst.empty()) continue;
                if (num == 1) bst.erase(prev(bst.end())); // 최소값 제거
                else bst.erase(bst.begin()); // 최대값 제거
            }
        }
        if (bst.empty()) cout << "EMPTY" << '\n';
        else cout << *prev(bst.end()) << ' ' << *bst.begin() << '\n'; // 최대값 최소값
    }
}