#include<iostream>
using namespace std;

int main(){
    //string test1 = "aA0 ";
    //string test2 = "zZ9 ";
    //cout<< test1[0]-'a' << " " << test1[1]-'a' << " " << test1[2]-'a' << " " << test1[3]-'a' << endl;
    //cout<< test2[0]-'a' << " " << test2[1]-'a' << " " << test2[2]-'a' << " " << test2[3]-'a' << endl;
    //위 코드의 실행 결과
    //0 -32 -49 -65
    //25 -7 -40 -65
    string in;
    int tmp,i;
    for(int j=0; j<100; j++){
        int little_big_num_space[4] = {0,};
        getline(cin,in);
        for(i=0; i<in.size(); i++){
            tmp = in[i]-'a';
            if(0 <= tmp && tmp <= 25) little_big_num_space[0]++;
            else if(-32 <= tmp && tmp <= -7) little_big_num_space[1]++;
            else if(-49 <= tmp && tmp <= -40) little_big_num_space[2]++;
            else if(tmp == -65) little_big_num_space[3]++;
        }
        //공백만 있으면 끝내기
        if(!little_big_num_space[0] && !little_big_num_space[1] && !little_big_num_space[2]) break;
        
        cout << little_big_num_space[0] << " " << little_big_num_space[1] << " " << little_big_num_space[2] << " " << little_big_num_space[3] <<endl;
    }
    
}