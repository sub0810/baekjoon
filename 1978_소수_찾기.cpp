#include<iostream>
using namespace std;
int main(){
    int N, cnt, tmp, i;
    cnt = 0;
    cin >> N;
    while(N--){
        cnt ++;
        cin >> tmp;
        if(tmp == 1) cnt--;
        for(i=2; i<tmp; i++){
            if(tmp%i == 0){
                cnt--;
                break;
            }
        }
    }
    cout << cnt;
}