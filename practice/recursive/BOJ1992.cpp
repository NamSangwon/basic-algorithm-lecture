#include <bits/stdc++.h>

using namespace std;

// 재귀 함수 기본 문제 - 쿼드 트리

void quad(int a, int b, int k);

int n;
char arr[64][64];
queue<char> q;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            char ch;
            cin >> ch;
            arr[i][j] = ch;
        }

    quad(0, 0, n);

    while(!q.empty()){
        cout << q.front();
        q.pop();
    }
    return 0;
}

void quad(int a, int b, int k){
    bool split = false;
    char tmp = arr[a][b];
    for(int i = a; i < a+k; i++)
        for(int j = b; j < b+k; j++)
            if (tmp != arr[i][j]){
                split = true;
                break;
            }

    if (!split) {
        q.push(tmp);
        return;
    }
    else{
        q.push('(');
        int num = k / 2;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                quad(a+i*num, b+j*num, num);
            }
        }
        q.push(')');
    }

}