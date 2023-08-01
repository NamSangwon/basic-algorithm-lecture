#include <bits/stdc++.h>

// 3/1 ~ 11/30 동안 계속 꽃을 피울 수 있도록 선택하는 꽃들의 최소 개수 구하기

using namespace std;

int n;
int start_day[100001]; 
int end_day[100001];


int main(){
    cin >> n;

    // 2 15 3 23 => 215 323
    for(int i = 0; i < n; i++){
        int s_mon, s_day, e_mon, e_day;
        cin >> s_mon >> s_day >> e_mon >> e_day;
        start_day[i] = s_mon * 100 + s_day;
        end_day[i] = e_mon * 100 + e_day;
    }

    int time = 301;
    int result = 0;
    int tmp = 0;
    do{
        for(int i = 0; i < n; i++){
            if (start_day[i] <= time) {
                tmp = max(tmp, end_day[i]);
            }
        }
        time = tmp;
        result++;
        cout << time << ' ' << result << endl;
    }while(time <= 1130);

    cout << result;
}