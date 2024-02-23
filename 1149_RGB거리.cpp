#include<iostream>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N,R,G,B,ans;
    int dp[1001][3];    //dp[이번에 색이][무슨색? R-G-B]
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> R >> G >> B;
        dp[i][0] = R + min(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = G + min(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = B + min(dp[i-1][0],dp[i-1][1]);
    }
    ans = min(dp[N][0],dp[N][1]);
    ans = min(ans,dp[N][2]);
    cout << ans;
}