#include<iostream>
using namespace std;
int dp[10001] = {0,};
int main(){
    int N,i,j;
    cin >> N;
    for(i=1; i<=N; i++) cin >> dp[i];

    for(i=1; i<=N; i++){
        for(j=1; j<=i; j++){
            dp[i] = max(dp[i],dp[j]+dp[i-j]);
        }
    }
    cout << dp[N];
}