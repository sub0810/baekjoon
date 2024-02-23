#include<iostream>

using namespace std;

int main(){
    int front=0;
    int back=-1;
    int inst_num;
    int queue[10000];
    
    string input;
    int input_num;

    cin >> inst_num;
    cin.ignore();

    while(inst_num--){
        cin >> input;
        if(input == "push"){
            cin >> input_num;
            queue[++back] = input_num;
        }
        else if(input == "pop"){
            if(back < front){
                cout << -1 << endl;
            }
            else{
                cout << queue[front++] << endl;
            }
        }        
        else if(input == "size"){
            cout << back - front + 1 << endl;
        }             
        else if(input == "empty"){
            if(back < front) cout << 1 << endl;
            else cout << 0 << endl;
        }     
        else if(input == "front"){
            if(back < front){
                cout << -1 << endl;
            }
            else cout << queue[front] << endl;
        }
        else if(input == "back"){
            if(back < front){
                cout << -1 << endl;
            }
            else cout << queue[back] << endl;
        }     
    }
}