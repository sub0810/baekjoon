#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M,N,x,y,T,year;
    cin >> T;
    while(T--){
        year = -1;
        cin >> M >> N >> x >> y;
        for(int i=x-1; i<=M*N; i+=M){
            if(i%N == y-1){
                year = i+1;
                break;
            }
        }
        
        cout << year << "\n";
    }
}