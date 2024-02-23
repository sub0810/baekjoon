#include<iostream>
#define MOD 1000000009
typedef long long ll;
using namespace std;
ll dp[1000000] = {0,};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,T,t,i;
    int max = 4;
    cin >> T;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(t=0; t<T; t++){
        cin >> n;
        if(n >= max){
            for(i=max; i<=n; i++){
                dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%MOD;
            }
            max = n;
        }
        cout << dp[n] << "\n";
    }
}