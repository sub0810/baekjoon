#include<iostream>
#include<cstring>

using namespace std;

int main(){
    char temp[100000];
    int i,j;
    int index = -1;
    string in = "";
    int special_case_check=0;


    getline(cin, in);
    in += " ";
    index = -1;
    for(i=0; i<in.size(); i++){
        if(in[i] == '<') special_case_check = 1;

        if(special_case_check){
            if(index != -1){    //공백 만난게 아니라 < 만났어도, 이전까지 나온 것 뒤집기
                for(j=index; j>-1; j--){
                    cout << temp[j];
                }
                index = -1;
            }
            cout << in[i];
            if(in[i] == '>') special_case_check = 0;
        }
        else if(in[i] == ' '){
            if (index == -1) continue;  //공백출력도 안하게 하기 위해서..
            for(j=index; j>-1; j--){
                cout << temp[j];
            }
            cout << " ";
            index=-1;
        }        
        else{
            temp[++index] = in[i];
        }
    }
}