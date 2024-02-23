#include<iostream>
using namespace std;
int main(){
    long long N, M, cnt, tmp;
    cin >> N;
    tmp = N/5;
    cnt = tmp;
    while(tmp>=5){
        tmp/=5;
        cnt += tmp;
    }
    cout << cnt;
}