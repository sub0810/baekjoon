#include<iostream>
using namespace std;
int main(){
    int arr[1001], N, i, j; //dp를 그 횟수때로 끝나는 경우? 로 할까
    int dp[1001] = {0,};
    int max_num = -1;
    cin >> N;
    dp[1] = 1;
    for(i=1; i<=N; i++) cin >> arr[i];
    for(i=2; i<=N; i++){
        for(j=1; j<i; j++){ //이전 녀석들 탐색
            if(arr[i] > arr[j] && dp[i] < dp[j]+1) dp[i] = dp[j]+1;
            if(dp[i] == 0) dp[i] = 1;
        }
    }

    for(i=N; i>0; i--){
        if(max_num < dp[i]) max_num = dp[i];
    }
    cout << max_num;
}