#include<iostream>
using namespace std;
int main(){
    //%1000000000
    int N,i,j;
    int result = 0;
    int arr[101][10]={0,};
    cin >> N;
//init
    arr[1][0] = 0;
    for(i=1; i<10; i++) arr[1][i] = 1;
//시작
    for(i=2; i<=N; i++){
        arr[i][0] = arr[i-1][1];
        arr[i][9] = arr[i-1][8];
        for(j=1; j<9; j++){
            arr[i][j] = (arr[i-1][j-1]+arr[i-1][j+1])%1000000000;
        }
    }
//출력
    for(i=0; i<10; i++) result = (result + arr[N][i])%1000000000;
    cout << result%1000000000;
}