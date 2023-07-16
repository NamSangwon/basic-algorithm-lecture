#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
    list<char> editor;
    string input_text;
    int M;
    char ir, input_char;

    cin >> input_text;
    
    // list 라이브러리 사용법 미숙지 (오답)
    for (auto c : input_text) editor.push_back(c);
    auto cursor = editor.end();

    cin >> M;

    while(M > 0){
        cin >> ir;
        if (ir == 'P') cin >> input_char;

        switch(ir){
            // D <-> L (오답)
            case 'D':
                if (cursor < editor.end()) cursor++;
                break;
            case 'L':
                if (cursor > editor.begin()) cursor--;
                break;
            case 'B':
                if (cursor > editor.begin()){
                    cursor--; // 커서 이동 안함 (오답)
                    editor.erase(cursor);
                }
                break;
            case 'P':
                editor.insert(cursor, input_char);
                break;
        }

        M--;
    }

    for (auto c : editor) cout << c; // 출력 안함 (오답)
}