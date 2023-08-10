#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> h;
int n, k;
string arr[100001];

int main(){
    cin >> n >> k;

    fill(arr, arr+100000, "-1");

    for(int i = 0; i < k; i++){
        string student_num;
        cin >> student_num;
        h[student_num] = i;
    }

    for(auto i : h) arr[i.second] = i.first;

    cout << "[answer]\n";
    int cnt = 0;
    for(int i = 0; i < 100001; i++){
        if (cnt >= n) break;
        if(arr[i] != "-1") {
            cout << arr[i] << '\n';
            cnt++;
        }
    }
}