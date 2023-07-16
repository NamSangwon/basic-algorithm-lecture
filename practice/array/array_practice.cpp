#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
    int student[12] = {};

    int N, K, result = 0;
    cin >> N, K;

    for (int i = 0; i < N; i++){
        int sex, cls;

        cin >> sex >> cls;

        if (sex == 1) student[cls - 1]++;
        else student[cls + 5]++;
    }

    for (int i = 0; i < 12; i++){
        if (student[i] != 0)  {
            result += student[i] / K;
            if (student[i] % K != 0) result++;
        }
    }

    cout << result;
}