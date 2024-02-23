#include<iostream>
using namespace std;
long long dp[100001][4];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T,n;
    cin >> T;
    dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
    dp[2][1] = 0; dp[2][2] = 1; dp[2][3] = 0;
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
    //dp[n번째에서][k로 끝난 것의 수]
    for(int i=4; i<100001; i++){
        dp[i][1] = (dp[i-1][2]+dp[i-1][3])%1000000009;
        dp[i][2] = (dp[i-2][1]+dp[i-2][3])%1000000009;
        dp[i][3] = (dp[i-3][1]+dp[i-3][2])%1000000009;
    }
    for(int i=0; i<T; i++){
        cin >> n;
        cout << (dp[n][1]+dp[n][2]+dp[n][3])%1000000009 << "\n";
    }

}