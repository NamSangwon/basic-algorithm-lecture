#include <bits/stdc++.h>

// parametric search 예제 (랜선 자르기) - 클론 코딩
// 조건을 만족하는 최소/최대값을 구하는 최적화 문제를 결정 문제로 변환하여 
// 이분 탐색을 수행하는 방법 => 따라서 문제 파악에 어려움을 느낄 수도 있음
// ex. N개를 만들 수 있는 랜선의 최대 길이 => 랜선 길이가 X일 때 랜선이 N개 이상인가?
// [parametric search는 그래프가 증가/감소 함수일 때만 사용 가능]

using namespace std;

int k, n;
int arr[10005];

// 이분 탐색 판단 함수 ()
bool solve(long long x){
    long long cur = 0;
    for(int i = 0; i < k; i++) cur += arr[i] / x;
    return cur >= x;
}

int main(){
    cin >> k >> n;

    for(int i = 0; i < k; i++) cin >> arr[i];

    long long st = 1;
    long long en = 0x7fffffff // == 2^31 - 1

    while(st < en){
        long long mid = (st + en + 1) / 2; // 무한 루프 방지
        if(solve(mid)) st = mid;
        else en = mid - 1;
    }

    cout << st;
}