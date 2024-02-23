#include<iostream>
#include<algorithm>
using namespace std;
int dp[1000001] = {0,};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N,i,tmp;
    cin >> N;
    //dp에는 연산 횟수를 담는다.
    dp[1] = 0; dp[2] = 1; dp[3] = 1;
    for(i=4; i<=N; i++){
        if(i%3 == 0){
            if(i%2 == 0){
                tmp = min(dp[i-1],dp[i/2]);
                dp[i] = min(dp[i/3],tmp)+1;
            }
            else{
                dp[i] = min(dp[i/3],dp[i-1])+1;
            }
        }
        else{
            if(i%2 == 0){
                dp[i] = min(dp[i/2],dp[i-1])+1;
            }
            else{
                dp[i] = dp[i-1]+1;
            }
        }
        //cout << "i: " << i << " " << dp[i] << "\n";
    }
    cout << dp[N];
}