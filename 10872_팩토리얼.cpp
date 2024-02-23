#include<iostream>
using namespace std;
int main(){
    int N, result;
    result = 1;
    cin >> N;
    for(int i=N; i>1; i--) result *= i;
    cout << result;
}