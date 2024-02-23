#include<iostream>
#include<stack>
using namespace std;
//스택에 값 확인하면서 계속 넣는다.
//만약 값이 연산자라면, check 필요
    //stack에 top에 있는 연산자보다 우선순위가 같거나 낮은 녀석을 만나면
        //stack에 있는 연산자를 모두 꺼내고, stack에 넣는다.
    //괄호가 닫히면 () 사이에 값을 모두 꺼낸다.
    //맨 끝에 도달하면, stack에 있는 값을 모두 꺼낸다.
int main(){
    string in;
    getline(cin, in);
    stack<char> s;
    char tmp;

    for(int i=0; i<in.size(); i++){
        tmp = in[i];
        if(tmp == '('){
            s.push(tmp);
        }
        else if(tmp == ')'){
            while(s.top() != '('){
                cout << s.top(); s.pop();
            }
            s.pop();    //'(' 꺼내기
        }
        else if(tmp == '*' || tmp == '/'){
            if(!s.empty() && s.top() != '('){
                while(!s.empty() && (s.top() == '*' || s.top() == '/')){
                    cout << s.top(); s.pop();
                }
            }
            s.push(tmp);
        }
        else if(tmp == '+' || tmp == '-'){
            if(!s.empty() && s.top() != '('){
                while(!s.empty() && (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-')){
                    cout << s.top(); s.pop();
                }
            }
            s.push(tmp);
        }
        else cout << tmp; //피연산자 출력
    }

    while(!s.empty()){
        cout << s.top(); s.pop();
    }
}