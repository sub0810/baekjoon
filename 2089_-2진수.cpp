#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    long long N; cin >> N;
    int next,tmp;
    next = N;
    if(N==0){
        cout << 0;
    }
    else{
        while(next != 1 && next != 0) //1이나 0이면 끝
        {
            tmp = next%-2;
            next /= -2;
            if(tmp == -1){
                tmp = 1;
                next += 1;
            }
            s.push(tmp);
        }
        if(next) s.push(next);   //next에 들어있는 1 넣기

        while(!s.empty()){
            cout << s.top(); s.pop();
        }
    }
}