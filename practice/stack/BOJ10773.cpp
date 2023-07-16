#include <bits/stdc++.h>

using namespace std;

int main(){
    int K;
    stack<int> s;

    cin >> K;

    while(K--){
        int num;
        cin >> num;

        if (num == 0){
            if (!s.empty()) s.pop();
        }
        else{
            s.push(num);
        }
    }
    int result = 0;
    while(s.size()){
        result += s.top();
        s.pop();
    }
    cout << result;
}