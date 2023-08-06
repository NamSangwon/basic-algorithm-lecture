#include <bits/stdc++.h>

using namespace std;

int n, t;
vector<int> v;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    cin >> n;

    while(n--){
        cin >> t;

        int result = 0;

        for(int i = 0; i < t; i++) {
            int num; 
            cin >> num;
            v.push_back(num);
        }

        for(int i = 0; i < (int)v.size(); i++){
            for(int j = i+1; j < (int)v.size(); j++){
                result += gcd(v[i], v[j]);
            }
        }

        cout << result << '\n';
        v.clear();
    }
}