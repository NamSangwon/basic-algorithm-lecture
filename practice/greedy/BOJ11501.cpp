#include <bits/stdc++.h>

using namespace std;

// 주식의 최대 이익 구하기

vector<int> stock;
vector<int> store;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            stock.push_back(num);
        }

        int result = 0;

        for(int i = 0; i < n; i++){
            if(stock[i] >= *max_element(stock.begin()+i, stock.end())) {
                for(auto num : store){
                    result += (stock[i] - num);
                }
                store.clear();
            }
            else{
                store.push_back(stock[i]);
            }
        }

        cout << result << '\n';
        stock.clear();
        store.clear();
    }
}