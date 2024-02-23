#include<iostream>
#include<algorithm>
using namespace std;
int input[10001] = {0,};
int N, point, smaller_max, idx;
int inc = 1;
int main(){
    cin >> N;
    for(int i=1; i<=N; i++) cin >> input[i];
    for(int i=N; i>1; i--){
        if(input[i-1] > input[i]){
            inc = 0; point = i-1; break;
        }
    }
    if(inc){
        cout << -1; return 0;
    }
    smaller_max = -1;
    for(int i=point+1; i<=N; i++){
        if(input[point] > input[i] && smaller_max < input[i]){
            smaller_max = input[i];
            idx = i;
        }
    }
    swap(input[point], input[idx]);
    sort(input+point+1,input+N+1, greater<>());
    for(int i=1; i<=N; i++) cout << input[i] << " ";
}