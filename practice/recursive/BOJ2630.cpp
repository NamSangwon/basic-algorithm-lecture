#include <bits/stdc++.h>

using namespace std;

void split(int a, int b, int c);

int arr[130][130];
int n;
int result[2];

int main(){
    cin >> n;

    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    split(0,0,n);

    cout << result[0] << '\n';
    cout << result[1] << '\n';
}

void split(int a, int b, int c){
    bool check = true;
    int tmp = arr[a][b];
    for(int i = a; i < a+c; i++)
        for(int j = b; j < b+c; j++)
            if(tmp != arr[i][j]){
                check = false;
                break;
            }

    if (check) {
        result[tmp]++;
        return;
    }
    else{
        int k = c / 2;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                split(a+j*k, b+i*k, k);
                // ex. 8 x 8
                // (0,0) (3,3) || (4,0) (7,3)
                // (0,4) (3,7) || (4,4) (7,7)
        
    }
}