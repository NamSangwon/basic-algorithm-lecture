#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> b;

int main(){
    int test_count;
    cin >> test_count;

    while(test_count--){
        int result = 0;
        int n, m;
        cin >> n >> m;

        // a 입력 받기
        for(int i = 0; i < n; i++) {
            int input_a;
            cin >> input_a;
            a.push_back(input_a);
        }
        // b 입력 받기
        for(int i = 0; i < m; i++) {
            int input_b;
            cin >> input_b;
            b.push_back(input_b);
        }

        // 순차 정렬 (필수 요옷 X)
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // a[i] > b[j] 검증
        for(int i = 0; i < n; i++){
            if(a[i] < b[0]) continue; // a 물고기가 b 물고기보다 크키가 작으면 스킵
            for(int j = 0; j < m; j++){
                if (a[i] > b[j]) result++;
            }
        }

        cout << result << '\n';
    }
}