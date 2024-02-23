#include<iostream>
using namespace std;
int main(){
    int N;
    long long arr[91][2];
    cin >> N;
    arr[1][0] = 0;
    arr[1][1] = 1;
    for(int i=2; i<=N; i++){
        arr[i][0] = arr[i-1][0]+arr[i-1][1];
        arr[i][1] = arr[i-1][0];
    }
    cout << arr[N][0]+arr[N][1];
}