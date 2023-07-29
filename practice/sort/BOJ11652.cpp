// #include <bits/stdc++.h>

// using namespace std;

// int n;
// long long arr[100005];

// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }

//     sort(arr, arr+n);

//     int cnt = 0;
//     // long long result = -1 * pow(2, 62) - 1;
//     long long result = -(1ll << 62) - 1; // 1을 long long으로 형변환하지 않고 1 << 62로 작성시 int overflow 발생
//     int mx_cnt = 0;

//     for(int i = 0; i < n; i++){
//         if(i = 0 || arr[i-1] == arr[i]) cnt++; // 시작 or 이전 값과 동일하다면 카운트 +1
//         else{ // 이전과 같은 값이 아니라면 카운트 등의 값들 초기화
//             if(cnt > mx_cnt){
//                 mx_cnt = cnt;
//                 result = arr[i-1];
//             }
//             cnt = 1;
//         }
//     }
//     if(cnt > mx_cnt) result = arr[n-1]; // 마지막 숫자 처리

//     cout << result;
// }

// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/f3feaf22016f4c9687b84ab6be2f4389
#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  int cnt = 0;
  long long mxval = -(1ll << 62) - 1; // 1을 long long으로 형변환하지 않고 1 << 62로 작성시 int overflow 발생
  int mxcnt = 0;
  for(int i = 0; i < n; i++){
    if(i == 0 || a[i-1] == a[i]) cnt++; // i가 0인 경우 앞쪽 식이 true이기 때문에 a[i-1]을 참조하지 않음
    else{
      if(cnt > mxcnt){
        mxcnt = cnt;
        mxval = a[i-1];
      }
      cnt = 1;
    }
  }
  if(cnt > mxcnt) mxval = a[n-1]; // 제일 마지막 수가 몇 번 등장했는지를 별도로 확인
  cout << mxval;
}

// 무한 루프를 도는 지 실행이 멈추지 않아 정답지를 첨부함
// (클론 코딩)