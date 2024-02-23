#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N, i, j, dp[100001];
    cin >> N;
    fill(dp,dp+100000,100001);

    dp[0]=0;
    dp[1]=1;
    for(i=1; i<317; i++) dp[i*i] = 1;
    for(i=2; i<=N; i++){
        for(j=1; j*j<=i; j++){
            dp[i] = min(dp[i], dp[i-j*j]+dp[j*j]);
        }
    }
    cout << dp[N];
}