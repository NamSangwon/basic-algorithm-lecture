#include <bits/stdc++.h>

// 트리 순회 (클론 코딩)

using namespace std;

int n;
// 이진 트리의 각 노드의 자식 노드를 저장하기 위한 배열
int lc[30];
int rc[30];

void pre_order(int cur){
    cout << char(cur + 'A' - 1);
    if(lc[cur] != 0) pre_order(lc[cur]);
    if(rc[cur] != 0) pre_order(rc[cur]);
}

void in_order(int cur){
    if(lc[cur] != 0) in_order(lc[cur]);
    cout << char(cur + 'A' - 1);
    if(rc[cur] != 0) in_order(rc[cur]);
}

void post_order(int cur){
    if(lc[cur] != 0) post_order(lc[cur]);
    if(rc[cur] != 0) post_order(rc[cur]);
    cout << char(cur + 'A' - 1);
}

int main(){
    cin >> n;

    // A, B, C, ...를 입력 받음 (char - 'A' + 1 => char == A -> 1)
    for(int i = 1; i <= n; i++){
        char p, left_child, right_child;
        cin >> p >> left_child >> right_child;
        if (left_child != '.') lc[p -'A'+1] = left_child - 'A' + 1;
        if (right_child != '.') rc[p -'A'+1] = right_child - 'A' + 1;
    }

    pre_order(1); cout << '\n';
    in_order(1); cout << '\n';
    post_order(1); cout << '\n';
}