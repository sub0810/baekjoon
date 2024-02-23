#include<iostream>
#include<algorithm>
using namespace std;
int W[11][11];
int arr[11] = {0,1,2,3,4,5,6,7,8,9,10};
int N, point, larger_min, idx;
int min_num = 1e9;
void cost_calculation(){
    int sum = 0;
    for(int i=N; i>1; i--){
        if(arr[i-1] < arr[i]){
            point = i-1; break;
        }
    }
    larger_min = 11;
    for(int i=point+1; i<=N; i++){
        if(arr[point] < arr[i] && larger_min > arr[i]){
            larger_min = arr[i];
            idx = i;
        }
    }
    swap(arr[point], arr[idx]);
    sort(arr+point+1,arr+N+1);
    for(int i=2; i<=N; i++){
        if(W[arr[i-1]][arr[i]] == 0) sum += 1e9;
        sum += W[arr[i-1]][arr[i]];
    }
    if(W[arr[N]][arr[1]] == 0) sum += 1e9;
    else sum += W[arr[N]][arr[1]];
    min_num = min(min_num, sum);
}
int main(){
    int loop_num = 1;
    int sum = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> W[i][j];
        }
    }
    //첫번째 경우
    for(int i=2; i<=N; i++){
        if(W[arr[i-1]][arr[i]] == 0) sum += 1e9;
        sum += W[arr[i-1]][arr[i]];
    }
    if(W[arr[N]][arr[1]] == 0) sum += 1e9;
    else sum += W[arr[N]][arr[1]];
    min_num = min(min_num, sum);
    //2번째~N!번째 경우
    for(int i=2; i<=N; i++) loop_num *= i;
    loop_num--;
    while(loop_num--) cost_calculation();

    cout << min_num;
}