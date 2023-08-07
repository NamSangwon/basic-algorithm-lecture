#include <bits/stdc++.h>

// 이분 탐색 기초

using namespace std;

int n, m;
vector<int> arr;

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
        bool check = false;
        int found;
        cin >> found;

        int st = 0;
        int en = n - 1;

        while(st <= en){
            int mid = (st + en) / 2;

            if(arr[mid] < found) st = mid + 1;
            else if (arr[mid] > found) en = mid - 1;
            else {
                check = true;
                break;
            }
        }

        if (check) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

}