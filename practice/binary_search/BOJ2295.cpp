#include <bits/stdc++.h>

// 세 수의 합 구하기 (이분 탐색의 응용 문제)
// O(n^3*lg(n))이 되도록 문제를 해결하였지만 시간 초과 발생!
// O(n^2*lg(n))이 되도록 하려면 두 원소만 더하는 two[] 배열을 추가한다.
// two[m] + a[k] = a[l] => two[m] = a[l] - a[k]

using namespace std;

int n;
vector<int> arr;
vector<int> two_add_num;
vector<int> three_add_num;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    // [[ O(n^2*lg(n)) ]]
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            two_add_num.push_back(arr[i]+arr[j]);

    // 정렬한 후 뒤에서 부터 값을 찾으면 그 값이 최대값!
    sort(two_add_num.begin(), two_add_num.end());

    // ex 1. [arr] = {10 20 30 40} => [two] = {30 40 50 50 60 70}
    // (1) (arr[3])40 - (arr[0])10 == (two[0])30 => 최대값은 (arr[3])40
    // ex 2. [arr] = {2 3 5 10 18} => [two] = {5 7 12 20 8 13 21 15 23 28} = {5 7 8 12 13 15 20 21 23 28}
    // (1~10) 18 - 2 != 5 ~ 28 
    // (11~15) 18 - 3 != 5 ~ 13
    // (16) 18 - 3 == 15
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(binary_search(two_add_num.begin(), two_add_num.end(), arr[i]-arr[j])){
                cout << arr[i];
                return 0;
            }
        }
    }

    // [[ O(n^3*lg(n)) ]]
    // for(int i = 0; i < n; i++)
    //     for(int j = i+1; j < n; j++)
    //         for(int k = j+1; k < n; k++)
    //             three_add_num.push_back(arr[i] + arr[j] + arr[k]);

    // int max_num = 0;

    // for(auto i : three_add_num){
    //     if(binary_search(arr.begin(), arr.end(), i)){
    //         max_num = max(max_num, i);
    //     }
    // }

    // cout << max_num;
}