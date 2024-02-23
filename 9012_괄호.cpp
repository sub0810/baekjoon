#include<iostream>

using namespace std;

int main(){
    int index;  //스택을 사용하는 대신, index를 확인해서 해보자
    int i;

    string in;
    char temp[50];
    int inst_num;

    cin >> inst_num;
    cin.ignore();
    while(inst_num--){
        index = -1;
        in = "";    //in 비워주고
        getline(cin,in);
        for(i = 0; i < in.size(); i++){
            if(in[i] == '('){
                temp[++index] = '(';
            }
            else if(in[i] == ')'){
                if(index == -1){
                    index = 0;
                    break; //예외처리 열린 '(' 없이, ')' 들어옴
                }
                if(temp[index] == '('){ //괄호 모양 정상적
                    index--;    //괄호 하나가 정상적으로 닫힘
                }
                else{   //괄호 모양 비정상적
                    index == 0;
                    break;
                }
            }
        }
        if(index == -1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}