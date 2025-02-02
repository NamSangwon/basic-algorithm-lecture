#include <bits/stdc++.h>

using namespace std;

int m, n;
vector<bool> state(10000001, true);

// 에라토스테네스의 체 함수 (효율적으로 소수를 구하는 함수)
// => 2 - 소수 O -> 2로 나누어 떨어지는 수(2, 4, 6, ...) 소수에서 제외
vector<int> sieve(int m, int n){
    state[1] = false;

    for(int i = m; i * i <= n; i++){
        if(!state[i]) continue; // => 해당 수가 소수가 아니라면 스킵
        for(int j = i*i; j <= n; j += i) // i의 배수 => 소수 제외 처리
            state[j] = false;
    }
}

int main(){
    cin >> m >> n;

    sieve(m, n);

    for(int i = m; i <= n; i++){
        if (state[i]) cout << i << '\n';
    }
}