#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
    int N, num;
    string ir;
    stack<int> s; // stack 라이브러리 사용하자!

    cin >> N;

    while(N--){
        cin >> ir;
        if (ir == "push"){
            cin >> num;
            s.push(num);
        }
        else if (ir == "top"){
            if(s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
        else if (ir == "size"){
            cout << s.size() << "\n";
        }
        else if (ir == "empty"){
            cout << s.empty() << "\n";
        }
        else if (ir == "pop"){
            if (s.empty()) cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        }
    }
}