#include<iostream>

using namespace std;

int main(){
    string in, in1, in2;
    string output;
    string stack[10000];
    int instruction_num;
    int count = -1;
    //count + 1개가 스택에 존재

    cin >> instruction_num;
    while(instruction_num--){
        cin >> in1;
        if(in1 =="push"){
            cin >> in2;
            stack[++count] = in2;
        }
        else if(in1 == "pop"){
            if(count == -1){
                cout << -1 << endl;
                continue;
            }
            output = stack[count--];
            cout << output << endl;
        }
        else if(in1 == "size"){
            cout << count+1 << endl;
        }
        else if(in1 == "empty"){
            if(count == -1){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(in1 == "top"){
            if(count == -1){
                cout << -1 << endl;
                continue;
            }
            output = stack[count];
            cout << output << endl;
        }
    }
}