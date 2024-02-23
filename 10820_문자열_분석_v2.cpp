#include<iostream>
using namespace std;

int main(){
    string in;
    int tmp,i;
    for(int j=0; j<100; j++){
        int little_big_num_space[4] = {0,};
        getline(cin,in);
        for(i=0; i<in.size(); i++){
            tmp = in[i]-0;
            if(97 <= tmp && tmp <= 122) little_big_num_space[0]++;
            else if(65 <= tmp && tmp <= 90) little_big_num_space[1]++;
            else if(48 <= tmp && tmp <= 57) little_big_num_space[2]++;
            else if(tmp == 32) little_big_num_space[3]++;
        }
        //공백만 있으면 끝내기
        if(!little_big_num_space[0] && !little_big_num_space[1] && !little_big_num_space[2]) break;
        
        cout << little_big_num_space[0] << " " << little_big_num_space[1] << " " << little_big_num_space[2] << " " << little_big_num_space[3] <<endl;
    }
    
}