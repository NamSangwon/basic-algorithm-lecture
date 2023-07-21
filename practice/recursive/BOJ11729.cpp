#include <bits/stdc++.h>

using namespace std;

// 하노이 탑 게임 (클론 코딩)

void hanoi(int from, int to, int cnt);

int main(){
    int k;
    cin >> k;

    cout << (1<<k) - 1 << '\n'; // 원판 옮긴 횟수 = 2^k - 1

    hanoi(1, 3, k);
}

void hanoi(int from, int to, int cnt){
    if (cnt == 1){
        cout << from << ' ' << to << "\n";
        return;
    }
    hanoi(from, 6-from-to, cnt-1); // n-1개의 원판을 1번 기둥 -> 2번 기둥으로 이동
    cout << from << ' ' << to << "\n"; // n번 원판을 1번 기둥 -> 3번 기둥으로 이동
    hanoi(6-from-to, to, cnt-1); // n-1개의 원판을 2번 기둥 -> 3번 기둥으로 이동
}