#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, result = 0;
    string line;
    stack<char> s;

    cin >> N;
    cin.ignore();

    while(N--){
        getline(cin, line);

        for(auto c : line){
            if (c == 'A'){
                if (s.empty() || s.top() != 'A') {
                    s.push(c);
                    continue;
                }
                else {
                    s.pop();
                }
            }
            else if (c == 'B') {
                if (s.empty() || s.top() != 'B') {
                    s.push(c);
                    continue;
                }
                else {
                    s.pop();
                }
            }
        }
        
        if (s.empty()) result++;
        while (!s.empty()) {s.pop();}
    }

    cout << result;
}