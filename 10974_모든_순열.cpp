#include<iostream>
#include<algorithm>
using namespace std;
int arr[9] = {0,1,2,3,4,5,6,7,8};
int N, point, larger_min, idx;
void print_permutation(){
    for(int i=N; i>1; i--){
        if(arr[i-1] < arr[i]){
            point = i-1; break;
        }
    }
    larger_min = 9;
    for(int i=point+1; i<=N; i++){
        if(arr[point] < arr[i] && larger_min > arr[i]){
            larger_min = arr[i];
            idx = i;
        }
    }
    swap(arr[point], arr[idx]);
    sort(arr+point+1,arr+N+1);
    for(int i=1; i<=N; i++) cout << arr[i] << " ";
    cout << "\n";
}
int main(){
    int loop_num = 1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    if(N==1){
        cout << 1; return 0;
    }
    else{
        for(int i=1; i<=N; i++) cout << arr[i] << " ";
        cout << "\n";
    }
    for(int i=2; i<=N; i++) loop_num *= i;
    loop_num--;
    while(loop_num--) print_permutation();
}