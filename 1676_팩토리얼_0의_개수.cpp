#include<iostream>
using namespace std;
int main(){
    long long N, M, cnt2, cnt5, tmp2, tmp5;
    cin >> N >> M;
    tmp2 = N/2; tmp5 = N/5;
    cnt2 = tmp2; cnt5 = tmp5;
    while(tmp5>=5){
        tmp5/=5; cnt5 += tmp5;
    }
    while(tmp2>=2){
        tmp2/=2; cnt2 += tmp2;
    }

    tmp2 = M/2; tmp5 = M/5;
    cnt2 -= tmp2; cnt5 -= tmp5;
    while(tmp5>=5){
        tmp5/=5; cnt5 -= tmp5;
    }
    while(tmp2>=2){
        tmp2/=2; cnt2 -= tmp2;
    }

    tmp2 = (N-M)/2; tmp5 = (N-M)/5;
    cnt2 -= tmp2; cnt5 -= tmp5;
    while(tmp5>=5){
        tmp5/=5; cnt5 -= tmp5;
    }
    while(tmp2>=2){
        tmp2/=2; cnt2 -= tmp2;
    }

    N = (cnt2 > cnt5) ? cnt5 : cnt2;
    cout << N;
}