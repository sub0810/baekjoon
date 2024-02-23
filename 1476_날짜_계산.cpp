#include<iostream>
using namespace std;
int main(){
    int E,S,M;
    int result = 1;
    int year[3] = {1,1,1};
    cin >> E >> S >> M;

    while(1){
        if(year[0] == E && year[1] == S && year[2] == M) break;
        result++;
        year[0]++; year[1]++; year[2]++;
        if(year[0] > 15) year[0] = 1;
        if(year[1] > 28) year[1] = 1;
        if(year[2] > 19) year[2] = 1;
    }
    cout << result;
}