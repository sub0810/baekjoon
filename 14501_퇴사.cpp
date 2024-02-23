#include<iostream>
using namespace std;
int N;
int T[16], P[16];
int max_money = -1;
void guess(int now_day, int money){
    if(now_day > N){
        //cout << "here : " << money << "\n";
        max_money = max(max_money, money);
        return;
    }
    if(now_day+T[now_day] <= N+1){
        guess(now_day+T[now_day], money+P[now_day]);
    }
    guess(now_day+1, money);
}
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> T[i] >> P[i];
    }
    guess(1,0);
    cout << max_money;
}