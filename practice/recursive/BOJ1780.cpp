#include <bits/stdc++.h>

// 색종이 자르기 문제 (※ <- 오답 표시)

using namespace std;

void cutting(int a, int b, int c); // ※ 3개의 인수 받기!

int n;
int arr[3001][3001];
int result[3] = {};

int main(){
    cin >> n;

    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    cutting(0, 0, n);

    for(int i = 0; i < 3; i++) cout << result[i] << "\n";
}

void cutting(int a, int b, int c){bool cut = false;
    int tmp = arr[a][b];
    for(int i = a; i < a + c; i++)
        for(int j = b; j < b + c; j++)
            if (tmp != arr[i][j]) {
                cut = true;
                break;
            }

    if(!cut) {
        result[tmp+1]++;
        return;
    }
    else {
        int n = c / 3; // ※ (9 -> 3 -> 1)
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++)
                cutting(a+i*n, b+j*n, n); // ※ 재귀식 구성 풀이 확인함
                // ex. 9 x 9
                // (0, 0) (2, 2) -> (0, 3) (2, 5) -> (0, 6) (2, 8)
                // (3, 0) (5, 2) -> (3, 3) (5, 5) -> (3, 6) (5, 8)
                // (6, 0) (8, 2) -> (6, 3) (8, 5) -> (6, 6) (8, 8)       
        }
    }
}