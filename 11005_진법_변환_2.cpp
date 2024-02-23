#include<iostream>
#include<stack>
using namespace std;
int main(){
    //10~35 -> 65~90 A-to-Z //B진법
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    stack<long long> s;
    long long N, B, tmp;
    char for_print;
    cin >> N >> B;

    while(N/B != 0){
        tmp = N%B;
        s.push(tmp);
        N/=B;
    }
    s.push(N);

    while(!s.empty()){
        if(s.top() >= 10){
            for_print = s.top()+55;
            cout << for_print;
        }
        else{
            cout << s.top();
        }
        s.pop();
    }
}