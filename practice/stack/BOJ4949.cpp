#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){

    while(true) {
        stack<char> s;
        string line;
        bool isValid = true;

        getline(cin, line);
        if (line == ".") break;

        // stack이 empty일 때 top 조회 시도를 통한 오류 발생 
        // bool 변수를 두어서 괄호 오류 유무 판단하도록 함
        for (auto c : line){
            if (c == '(' || c == '[') s.push(c);

            if (c == ')'){
                if (s.empty() || s.top() != '(') {
                    isValid = false;
                    break;
                }
                else s.pop();
            }
            else if (c == ']'){
                if (s.empty() || s.top() != '[') {
                    isValid = false;
                    break;
                }
                else s.pop();
            }
        }
        if (isValid) cout << "yes\n";
        else cout << "no\n";
    }
}