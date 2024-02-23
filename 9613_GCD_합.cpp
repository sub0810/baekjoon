#include<iostream>
using namespace std;
int GCD(int A, int B){
    if(B == 0) return A;
    else return GCD(B,A%B);
}
int main(){
    long long t, n, arr[100], sum, i, j;
    cin >> t;
    cin.ignore();
    while(t--){
        cin >> n;
        cin.ignore();
        sum = 0;
        for(i=0; i<n; i++){
            cin >> arr[i];
        }
        for(i=0; i<n-1; i++){
            for(j=i+1; j<n; j++){
                sum += GCD(arr[i],arr[j]);
            }
        }
        cout << sum << endl;
    }
}