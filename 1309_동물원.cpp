#include<iostream>
using namespace std;
#define MOD 9901
#define MAX 100001
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    int dp[MAX][3]; //없음, 왼, 오
    dp[1][0] = 1; dp[1][1] = 1; dp[1][2] = 1;
    for(int i=2; i<=N; i++){
        dp[i][0] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%MOD;
        dp[i][1] = (dp[i-1][0]+dp[i-1][2])%MOD;
        dp[i][2] = (dp[i-1][0]+dp[i-1][1])%MOD;
    }
    cout << (dp[N][0]+dp[N][1]+dp[N][2])%MOD;
}