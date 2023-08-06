#include <bits/stdc++.h>

using namespace std;

int n, t;
vector<int> v;

// 최대 공약수(GCD) => GCD(12, 8) = GCD(8, 4) = GCD(4, 0) = 4 (유클리드 호제법)
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