#include<iostream>
#include<stack>
//이게 이제 stack에 값 넣다가, 연산자가 나오면, 맨 위 두 개를 꺼내서 계산하고,
//다시 stack에 집어넣는걸 반복하는 작업이란말이지
using namespace std;

int main(){
    int N;
    double tmp1, tmp2; //값 두개 꺼내서 계산할 때 사용할 것
    stack<double> s;
    string in;
    double result = 0;
    //(input_문자-'A')+1 를 index로 이용하면 되겠다.. //그냥 숫자 1~26에 대응되도록
    double value_arr[27];

    cin >> N;
    cin.ignore();
    getline(cin, in);   //후위 표기식이 여기에 담겨있다.

    for(int j=1; j<=N; j++){
        cin >> value_arr[j];
    }
//세팅 끝, 본 코드 시작
    for(int i=0; i<in.size(); i++){
        if(in[i] == '*'){
            tmp1 = s.top(); s.pop();
            tmp2 = s.top(); s.pop();
            result = tmp2 * tmp1;
            s.push(result);
        }
        else if(in[i] == '/'){
            tmp1 = s.top(); s.pop();
            tmp2 = s.top(); s.pop();
            result = tmp2 / tmp1;
            s.push(result);
        }
        else if(in[i] == '+'){
            tmp1 = s.top(); s.pop();
            tmp2 = s.top(); s.pop();
            result = tmp2 + tmp1;
            s.push(result);
        }
        else if(in[i] == '-'){
            tmp1 = s.top(); s.pop();
            tmp2 = s.top(); s.pop();
            result = tmp2 - tmp1;
            s.push(result);
        }
        else{
            s.push(value_arr[(in[i]-'A')+1]);
        }
    }
    result = s.top();
    cout << fixed;
    cout.precision(2);
    cout << result;
}