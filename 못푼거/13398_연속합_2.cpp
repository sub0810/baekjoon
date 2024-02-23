#include<iostream>
using namespace std;
int main(){
    int arr[100001], n, i, tmp, min_value, idx;
    int dp[100001] = {0,};
    cin >> n;
    for(i=1; i<=n; i++){
        cin >> arr[i];
    }
    tmp = 0;
    min_value = 0;
    idx = -1;
    for(i=1; i<=n; i++){
        tmp += arr[i];
        if(tmp > 0){
            arr[i] = tmp;
            min_value = min(min_value, arr[i]);
        }
        else{
            if(idx != -1){
                tmp = 0;
                min_value = 0;
                idx = -1;
            }
            else{
                idx = i;
                min_value = min(min_value,arr[i]);
                tmp = tmp-min_value;
                arr[i] = tmp;
            }
        }
    }
    tmp = -1001;
    for(i=1; i<=n; i++){
        if(arr[i] > tmp) tmp = arr[i];
    }
    cout << tmp;
}