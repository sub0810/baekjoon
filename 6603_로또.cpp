#include<iostream>
using namespace std;
int N;
int arr[50], combArr[50];
void Combination(int combArr[50], int arr[50], int n, int r, int index, int target){
    if(r==0){
        for(int i=0; i<index; i++) cout << arr[combArr[i]] << " ";
        cout << "\n";
    }
    else if(target == n) return;
    else{
        combArr[index] = target;
        Combination(combArr, arr, n, r-1, index+1, target+1);
        Combination(combArr, arr, n, r, index, target+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){
        cin >> N;
        if(N==0) break;
        for(int i=0; i<N; i++) cin >> arr[i];
        Combination(combArr, arr, N, 6, 0, 0);
        cout << "\n";
    }
}