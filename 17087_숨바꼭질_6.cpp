#include<iostream>
using namespace std;
int GCD(int A, int B){
    if(B == 0) return A;
    else return GCD(B,A%B);
}
int main(){
    long long N, S, pos[100000], i, j, tmp; //pos에 S로부터의 거리정보 담기
    cin >> N >> S;
    cin.ignore();
    for(i=0; i<N; i++){
        cin >> tmp;
        pos[i] = (tmp>S) ? tmp-S : S-tmp;
    }
    tmp = pos[0];
    for(i=1; i<N; i++){ //최대공약수 GCD 구하기
        tmp = GCD(tmp,pos[i]);
    }
    cout << tmp;
}