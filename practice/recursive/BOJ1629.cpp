#include <bits/stdc++.h>

using namespace std;

// [a power b mod c (a ^ b % c)]의 값은? (클론 코딩)

int func(int a, int b, int c);

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    cout << func(a, b, c);
}

// ex) 14 ^ 3 % 3 = 2744 % 3 = 2
// = (14 % 3)(14 % 3)(14 % 3) = (2)(14 % 3)(14 % 3)
// = (28 % 3)(14 % 3) = (1)(14 % 3) = 2
int func(int a, int b, int c){
    if (b == 1) return a % c;
    int val = func(a, b/2, c);
    val *= val % c;
    if (b % 2 == 0) return val;
    return val * a % c;
}
