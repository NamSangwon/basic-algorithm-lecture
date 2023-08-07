#include <bits/stdc++.h>

// 숫자 카드의 개수 구하기 
// [힌트] 해당 카드가 위치할 수 있는 최대 인덱스와 최소 인덱스의 차가 결과값이다.

using namespace std;

int n, m;
vector<int> arr;

// 그림을 그리면 이해하기 쉬움
// 해당 카드가 위치할 수 있는 최소 인덱스 ※( == stl의 lower_bound() )
int lower_idx(int target){
    int st = 0;
    int en = n;

    while(st < en){
        int mid = (st + en) / 2;
        if (arr[mid] < target) st = mid + 1;
        else en = mid;
    }

    return st;
}
// 해당 카드가 위치할 수 있는 최대 인덱스 ※( == stl의 upper_bound() )
int upper_idx(int target){
    int st = 0;
    int en = n;

    while(st < en){
        int mid = (st + en) / 2;
        if (arr[mid] <= target) st = mid + 1;
        else en = mid;
    }

    return st;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    cin >> m;
    while(m--){
        int num;
        cin >> num;

        cout << upper_idx(num) - lower_idx(num) << ' ';
    }
}