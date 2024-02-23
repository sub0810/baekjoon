#include<iostream>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long B, result,for_cal;
    string N;
    result = 0;
    cin >> N >> B;
    for(int i=0; i<N.size(); i++){
        for_cal = N[i];
        if(for_cal >= '0' && for_cal <= '9') result = result * B + (for_cal-'0');
        else if(for_cal >= 'A' && for_cal <= 'Z') result = result * B + (for_cal-'A'+10);
    }
    cout << result;
}