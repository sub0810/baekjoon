#include<iostream>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    bool prime_num[1000001];
    long long T,N,i,j,cnt;

    cin >> T;
    for(i=2; i<1000001; i++) prime_num[i] = true;
    for(i=2; i<1000001; i++){
        if(prime_num[i]){
            for(j=i*i; j<1000001; j+=i) prime_num[j] = false;
        }
    }

    while(T--){
        cin >> N;
        cnt = 0;
        for(i=2; i<=N/2; i++){
            if(prime_num[i] && prime_num[N-i]) cnt++;
        }
        cout << cnt << "\n";
    }
}