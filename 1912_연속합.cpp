#include<iostream>
using namespace std;
int main(){
    int arr[100001], n, i, tmp;
    int dp[100001] = {0,};
    cin >> n;
    for(i=1; i<=n; i++){
        cin >> arr[i];
    }
    tmp = 0;
    for(i=1; i<=n; i++){
        tmp += arr[i];
        if(tmp > 0){
            arr[i] = tmp;
        }
        else{
            tmp = 0;
        }
    }
    tmp = -1001;
    for(i=1; i<=n; i++){
        if(arr[i] > tmp) tmp = arr[i];
    }
    cout << tmp;
}