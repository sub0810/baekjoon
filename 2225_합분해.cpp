#include<iostream>
typedef long long ll;
#define MAX 201
#define MOD 1000000000
using namespace std;
int main(){
    int N,K,n,k,j;
    ll dp[MAX][MAX]={0,};   //dp[N][K] N을 만들 때, K번째 칸에 들어가는 경우 수
    //아이디어는 이전 방식과 동일. 다음 단계로 넘어갈 때, 각 칸에 한개 꼽는 느낌으로
    cin >> N >> K;

    for(n=0; n<=N; n++) dp[n][1] = 1;
    //k개 중에서 마지막 더하는 숫자를 0~N으로 한개씩 늘려가면서 고정하면
    //(k번쨰가 0~N으로 고정됨) -> k-1개로 남은 녀석들을 만드는 문제로 소분
    //dp[n][k] = dp[n][k-1] + dp[n-1][k-1] + ... + dp[1][k-1] + dp[0][k-1];
    for(k=2; k<=K; k++){
        for(n=0; n<=N; n++){
            for(j=0; j<=n; j++){
                dp[n][k] += dp[n-j][k-1];
                dp[n][k] %= MOD;
            }
        }
    }
    
    cout << dp[N][K];
}
