#include<iostream>
#include<stack>
using namespace std;

int main(){
    int index = -1; //+, - 표시 (push, pop)
    int inst_num,N;
    int input;
    int where = 1;  //숫자 몇번을 stack에 넣을지 고민하고 있나??
    int fin = 1;    //해당 문자에 대한 해결책 찾을 수 있는 상태
    stack<int> stack;
    char seq[200000];    //+, - 정보 저장


    cin >> inst_num;
    N = inst_num;
    cin.ignore();

    stack.push(where++);    //1넣어두고, where을 2로 설정해두고 들고있는다.
    seq[++index] = '+';
    while(fin && (inst_num--)){
        //stack에 push하는 순서는 반드시 오름차순이어야
        cin >> input;
        cin.ignore();

        //cout << "stack check: ";
        //for(int i=0; i<=index; i++) cout << seq[i];
        //cout << endl;
        //cout << "where check: " << where << endl;

        while(where <= input){    //where부터 input까지 stack에 넣을 수 있음
               //다르면 일단 넣어
            seq[++index] = '+';
            stack.push(where++);
        }
        if(stack.top() == input){   //같으면 pop
            seq[++index] = '-';
            stack.pop();
        }
        else{   //top에 있는게 더 숫자가 다르면
            //망한 경우
            fin = 0;
            //cout << "fin2";
        }
    }
    if(fin){
        for(int i=0; i<index; i++) cout << seq[i] << '\n';
        cout << seq[index];
    }
    else cout << "NO";
}