#include<iostream>
using namespace std;
int N,S;
long long arr[21] = {0,};
int cnt = 0;
void calcul(int now, int idx);
int main(){
    cin >> N >> S;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
    calcul(0,1);
    cout << cnt;
}
void calcul(int now, int idx){  //이번에 참조할 index
    if(idx > N) return;
    if(now+arr[idx] == S){
        cnt++;
    }
    calcul(now+arr[idx], idx+1);
    calcul(now, idx+1);
}