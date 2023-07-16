#include <bits/stdc++.h>

using namespace std;

// 쇠막대기 자르기
int main(){
    stack<char> s;
    string cut;
    int result = 0;
    char before_ch = ' ';

    getline(cin, cut);

    for(auto ch : cut){
        if (ch == '(') { 
            s.push(ch);
        }

        if (s.top() == '(' && ch == ')'){ // if lazer
            s.pop();
            if (before_ch == ')') result++;
            else result += s.size();
            cout << "result : " << result << endl;
        }

        before_ch = ch;
    }

    cout << result;
}