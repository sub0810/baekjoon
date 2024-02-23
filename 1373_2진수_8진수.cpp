#include<iostream>
using namespace std;
int main(){
    string bit; cin >> bit;
    int i, tmp, each_pos;
    //3개씩 잘랐을 때, 앞에 남은 수 처리
    tmp = bit.size()%3;
    each_pos = 0;
    if(tmp == 1){
        cout << bit[0]-'0';
    }
    else if(tmp == 2){
        cout << ((bit[0]-'0')*2)+(bit[1]-'0');
    }
    //3개씩 처리
    for(i=tmp; i<bit.size(); i+=3){
        cout << ((bit[i]-'0')*4)+((bit[i+1]-'0')*2)+(bit[i+2]-'0');
    }
}