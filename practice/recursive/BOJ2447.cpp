#include <bits/stdc++.h>

using namespace std;

void star(int a, int b, int k);

int n;
char arr[2300][2300];
int test = 0;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++) fill(arr[i], arr[i]+n, ' '); // ※ 배열 ' '로 초기화

    star(0, 0, n);

    // 2차원 배열 출력 2중 for문 사용 대체 코드
    for(int i = 0; i < n; i++){
            cout << arr[i] << "\n";
    }
}

// case에서 배열에 * 추가
void star(int a, int b, int k){
    // ## 복잡하게 생각할 필요 X ##
    // int num = k / 3;
    // for(int i = a; i < a+k; i++){
    //     for(int j = b; j < b+k; j++){
    //         if (i >= a+num && i <= b-num && j >= a+num && j <= b-num) // 중심부일 시
    //             arr[i][j] = ' ';
    //         else arr[i][j] = '*';
    //     }
    // }
    if (k == 1) {
        arr[a][b] = '*';
        return;
    }

    int num = k / 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (!(i == 1 && j == 1))
                star(a+i*num, b+j*num, num);
        }
    }
}