#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    stack<char> s;

    getline(cin, str);

    // 곱하기 괄호에 있는 값은 미리 곱하기 (ex. [()()] = 2*3+2*3)
    int sum = 0; // 누적해서 더해질 값
    int num = 1; // 곱해질 값

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
        num *= 2; // 소괄호가 나오면 곱해질 값 2배 증가
        s.push(str[i]);
        }
        else if(str[i] == '['){
        num *= 3; // 대괄호가 나오면 곱해질 값 3배 증가
        s.push(str[i]);
        }
        else if(str[i] == ')'){
        if(s.empty() || s.top() != '('){
            cout << 0;
            return 0;
        }
        if(str[i-1] == '(') sum += num; // 직전 괄호가 여는 괄호였다면 sum에 값 추가
        s.pop();
        num /= 2; // 소괄호 쌍이 사라졌으니 2로 나눔      
        }
        else{ // str[i] == ']'
        if(s.empty() || s.top() != '['){
            cout << 0;
            return 0;
        }
        if(str[i-1] == '[') sum += num; // 직전 괄호가 여는 괄호였다면 sum에 값 추가
        s.pop();
        num /= 3; // 대괄호 쌍이 사라졌으니 3로 나눔
        }
    }
    if(s.empty()) cout << sum;
    else cout << 0;
}