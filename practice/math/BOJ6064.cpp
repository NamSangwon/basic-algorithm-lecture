#include <bits/stdc++.h>

// 연립 합동 방정식 문제
// 카잉 달력의 마지막 해 구하기 (클론 코딩)

using namespace std;

int t;

// 유클리드 호제법으로 구한 최대공약수
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

// A x B = gcd(A, B) x lcm(A, B)를 통해 구한 최소공배수
// A / gcd(A, B)를 먼저하는 이유는 오버플로우를 방지하기 위함이다.
int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

int solve(int m, int n, int x, int y){
    // (M = 10 & N = 12) 첫 번째 해 = <1:1>, 11번째 해 = <1:11>
    if (m == x) x = 0; 
    if (n == y) y = 0;

    int l = lcm(m, n); // 마지막 해 = m과 n의 최소공배수

    for(int i = x; i < l; i += m){
        if(i % n == y) return i; // i번째 해 = 마지막 해
    }

    return -1; // 유효하지 않은 표현
 }

int main(){
    cin >> t;

    while(t--){
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        cout << solve(m, n, x, y) << '\n';
    }
}