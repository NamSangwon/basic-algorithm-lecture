#include <bits/stdc++.h>

using namespace std;

// 회의실 배정 
// (정렬을 사용하여 이중 for문을 대체하는 방법도 존재 <- 내가 짠 코드보다 효율적이므로 정답 참고) 

int n;
vector<int> start_time;
vector<int> end_time;

int main(){
    cin >> n;

    for(int i = 0 ; i < n; i++){
        int start, end;
        cin >> start >> end;
        start_time.push_back(start);
        end_time.push_back(end);
    }


    int t = *min_element(end_time.begin(), end_time.end());
    int end = *max_element(end_time.begin(), end_time.end());
    int result = 1;

    do{
        int end_min = 999999;
        for(int i = 0; i < n; i++){
            if(start_time[i] < t) continue;
            end_min = min(end_min, end_time[i]);
        }
        t = end_min;
        result++;
    } while(t != end);

    cout << result;
}