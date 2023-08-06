#include <bits/stdc++.h>

using namespace std;

// 이항계수 구하기 (클론 코딩)
// nPk = n! / (n-k)! <= 순서 고려 O
// nCk = n! / ((n-k)! * k!) <= 순서 고려 X
// nCk = (n-1)Ck + (n-1)C(k-1) => 이항 계수의 특성 (n과 k의 값이 클 때 사용)

int n, k;
int comb[1002][1002]; // comb[1][1] = 1C1
int mod = 10007;

int main(){
    cin >> n >> k;

    // 1C1 ~ 1000C1000의 이항계수 배열에 저장
    for(int i = 1; i <= 1000; i++){
        comb[i][0] = 1; // nC0 = 1
        comb[i][i] = 1; // nCn = 1
        for(int j = 1; j < i; j++){ // nCk = (n-1)Ck + (n-1)C(k-1)
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % mod; // 오버플로우에 대비하여 모듈러 연산을 저장
        }
    }

    cout << comb[n][k] << '\n';
}