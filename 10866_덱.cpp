#include<iostream>

using namespace std;

int main(){
    int front=0;
    int back=-1;
    int inst_num;
    int dequeue[10000];
    //circulus하게 접근??
    string input;
    int input_num;

    cin >> inst_num;
    cin.ignore();

    while(inst_num--){
        cin >> input;
        if(input == "push_front"){
            cin >> input_num;
            dequeue[((--front) + 10000)%10000] = input_num;
        }
        else if(input == "push_back"){
            cin >> input_num;
            dequeue[((++back) + 10000)%10000] = input_num;
        }        
        else if(input == "pop_front"){
            if(back-front == -1){
                cout << -1 << endl;
            }
            else{
                cout << dequeue[((front++) + 10000)%10000] << endl;
            }            
        }        
        else if(input == "pop_back"){
            if(back-front == -1){
                cout << -1 << endl;
            }
            else{
                cout << dequeue[((back--) + 10000)%10000] << endl;
            }
        }        
        else if(input == "size"){
            cout << back-front+1 << endl;
        }             
        else if(input == "empty"){
            if(back-front == -1) cout << 1 << endl;
            else cout << 0 << endl;
        }     
        else if(input == "front"){
            if(back-front == -1){
                cout << -1 << endl;
            }
            else cout << dequeue[(front + 10000)%10000] << endl;
        }
        else if(input == "back"){
            if(back-front == -1){
                cout << -1 << endl;
            }
            else cout << dequeue[(back + 10000)%10000] << endl;
        }
    }
}