#include <bits/stdc++.h>

using namespace std;

// k개의 숫자 중 6개를 중복없이 선택하는 로또 (주석 = 오답 수정)

int k;
int input[13];
int output[13];

void func(int n, int cur);

int main(){
    while(1){
        cin >> k;
        if (k == 0) break;

        for(int i = 0; i < k; i++) cin >> input[i];

        func(0, 0);

        cout << '\n';
    }
}

void func(int n, int cur){
    if(n == 6) {
        for(int i = 0; i < 6; i++) cout << output[i] << ' ';
        cout << '\n';
        return;
    }

    // 입력 값 : 1, 2, 3 | 2개 선택 | k = 2 & s = 1 2 3
    // 1, 2 (func(0,0) -> func(1,1)) -> 1, 3 (func(0,0) -> func(1,2))
    // 2, 3 (func(0,1) -> func(1,2)) -> (종료)
    for(int i = cur; i < k; i++){
        output[n] = input[i];
        func(n+1, i+1);
    }
}