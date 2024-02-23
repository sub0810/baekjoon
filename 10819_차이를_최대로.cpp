#include<iostream>
#include<algorithm>
using namespace std;
int arr[9];
int N, point, larger_min, idx;
int max_num = -1;
void calculation_result(){
    int sum, tmp;
    for(int i=N-1; i>0; i--){
        if(arr[i-1] < arr[i]){
            point = i-1; break;
        }
    }
    larger_min = 200;
    for(int i=point+1; i<N; i++){
        if(arr[point] < arr[i] && larger_min > arr[i]){
            larger_min = arr[i];
            idx = i;
        }
    }
    swap(arr[point], arr[idx]);
    sort(arr+point+1,arr+N);
    sum = 0;
    for(int i=1; i<N; i++){
        tmp = arr[i-1]-arr[i];
        if(tmp < 0) tmp = 0 - tmp;
        sum += tmp;
    }
    max_num = max(sum,max_num);
    //for(int i=0; i<N; i++) cout << arr[i] << " ";
    //cout << "\n";
    //cout << sum << "\n";
}
int main(){
    fill(arr,arr+9,200);
    int loop_num = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr, arr+9);
    for(int i=2; i<=N; i++) loop_num *= i;
    loop_num--;
    while(loop_num--) calculation_result();
    cout << max_num;
}