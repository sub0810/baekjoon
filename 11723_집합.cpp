#include<iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    string inst;
    int M, x;
    int S[21] = {0,};
    cin >> M;
    while(M--){
        cin >> inst;
        if(inst == "add"){
            cin >> x;
            S[x] = 1;
        }
        else if(inst == "remove"){
            cin >> x;
            S[x] = 0;
        }
        else if(inst == "check"){
            cin >> x;
            if(S[x]) cout << 1;
            else cout << 0;
            cout << "\n";
        }
        else if(inst == "toggle"){
            cin >> x;
            if(S[x]) S[x] = 0;
            else S[x] = 1;
        }
        else if(inst == "all"){
            fill(S,S+21,1);
        }
        else if(inst == "empty"){
            fill(S,S+21,0);
        }
    }
}