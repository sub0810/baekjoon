#include<iostream>
using namespace std;
int main(){
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    string AB = ""; AB += to_string(A); AB += to_string(B);
    string CD = ""; CD += to_string(C); CD += to_string(D);
    cout << stol(AB) + stol(CD);
}