#include <bits/stdc++.h>

// 좌표 압축 (중복된 원소를 제거하기 위해 stl에 있는 함수를 사용)

using namespace std;

int n;
int arr[100002];
vector<int> uni;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        uni.push_back(arr[i]);
    }

    sort(uni.begin(), uni.end());

    // ============ [중복 제거] =================
    // (아래의 주석 부분은 stl 함수를 사용하지 않고 배열 2개를 사용하는 예)
    // for(int i = 0; i < uni.size(); i++){
    //     if(i == 0 || uni[i] != uni[i-1]) uni.push_back(arr[i]);
    // }
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    // =========================================

    // 해당 원소의 인덱스 - 시작 인덱스 = 해당 원소보다 작은 워소의 개수
    for(int i = 0; i < n; i++){
        cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin() << ' ';
    }
}