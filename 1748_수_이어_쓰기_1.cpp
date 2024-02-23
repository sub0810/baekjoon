#include<iostream>
#define MAX 100000001
using namespace std;
int main(){
    int N; cin >> N;
    int prev_range = 1;
    int range = 10;
    int mult = 1;
    int cnt = 0;
    while(range < MAX){
        range--;
        if(range < N){
            cnt += mult*(range - prev_range + 1);
        }
        else{
            cnt += mult*(N - prev_range + 1);
            break;
        }
        prev_range = range+1;
        range = prev_range * 10;
        mult++;
    }
    if(N == MAX-1) cnt += 9;
    cout << cnt;
}