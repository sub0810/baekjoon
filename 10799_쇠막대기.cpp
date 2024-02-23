#include<iostream>

using namespace std;

int main(){
    int cnt = 0;
    int num = 0;    //조각 개수
    int laser = 0; //레이저인지 확인
    string in = "";
    getline(cin, in);

    for(int i=0; i<in.size(); i++){
        if(in[i] == '('){
            cnt++;
            laser = 1;
        }
        else if(laser == 1 && in[i] == ')'){    //레이저
            num+=(--cnt);
            laser = 0;
        }
        else{   //레이저 아님, 그냥 )
            laser = 0;
            cnt--;
            num++;
        }
    }

    cout << num;
}