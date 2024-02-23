#include<iostream>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, tmp;
    cin >> N;
    tmp = 2;

    if(N == 1) return 0;
    while(N != 1){
        if(N%tmp == 0){
            cout << tmp << "\n";
            N/=tmp;
        }
        else tmp++;
    }
}