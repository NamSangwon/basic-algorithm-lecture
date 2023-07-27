#include <bits/stdc++.h>

using namespace std;

int n = 10;
int arr[100001] = {3, 5, 7, 1, 4, 0, -1, -4, 2, 10};
int tmp[100001];

// 오답 후 클론 코딩
void merge(int start, int end){
    int mid = (start + end) / 2;
    int l_idx = start; // ※
    int r_idx = mid; // ※
    for(int i = start; i < end; i++){ 
        if (r_idx == end) tmp[i] = arr[l_idx++];
        else if (l_idx == mid) tmp[i] = arr[r_idx++];
        else if(arr[l_idx] <= arr[r_idx]) tmp[i] = arr[l_idx++];
        else tmp[i] = arr[r_idx++];
    }
    for(int i = start; i < end; i++) arr[i] = tmp[i]; // ※
}

void merge_sort(int start, int end){
    if (start == end - 1) return; // ※
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, end);
}

int main(){
    merge_sort(0, n);
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}