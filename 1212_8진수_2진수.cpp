#include<iostream>
#include<stack>
using namespace std;
int main(){
    string octal; cin >> octal;
    int tmp,i,j;
    int is_first = 1;
    stack<int> s;
    //0인 경우를 제외하면, 첫째 자리 1이어야 함
    if(octal[0] == '0') cout << 0;
    else{
        tmp = octal[0]-'0';
        for(j=0; j<3; j++){
            s.push(tmp%2); tmp/=2;
        }
        for(j=0; j<3; j++){
            if(is_first){
                if(s.top()){
                    cout << s.top();
                    is_first = 0;
                }
                s.pop();
            }
            else{
                cout << s.top(); s.pop();
            }
        }
    }
    //나머지 처리
    for(i=1; i<octal.size(); i++){
        tmp = octal[i]-'0';
        for(j=0; j<3; j++){
            s.push(tmp%2); tmp/=2;
        }
        for(j=0; j<3; j++){
            cout << s.top(); s.pop();
        }
    }
}