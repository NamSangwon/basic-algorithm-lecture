#include <bits/stdc++.h>

// quick_sort 클론 코딩

using namespace std;

int n = 10;
int arr[100001] = {3, 5, 7, 1, 4, 0, -1, -4, 2, 10};

void quick_sort(int start, int end){
    if (end <= start + 1) return;
    int pivot = arr[start];
    int l = start + 1;
    int r = end - 1;
    while(1){
        while(l <= r && arr[l] <= pivot) l++;
        while(l <= r && arr[r] >= pivot) r++;
        if(l > r) break;
        swap(arr[l], arr[r]); // segmentation fault 발생
    }
    swap(arr[start], arr[r]); // segmentation fault 발생
    quick_sort(start, r);
    quick_sort(r+1, end);
}

int main(){
    quick_sort(0, n);
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}