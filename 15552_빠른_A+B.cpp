#include<iostream>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long T; cin >> T;
    int A,B;
    while(T--){
        cin >> A >> B;
        cout << A+B << "\n";
    }
}