#include<iostream>
using namespace std;
int main(){
    char tmp;
    string in; getline(cin, in);

    for(int i=0; i<in.size(); i++){
        tmp = in[i]-0;
        if(97 <= tmp && tmp <= 122){//소문자
            tmp = (tmp-'a'+13)%26 + 97;
            cout << tmp;
        } 
        else if(65 <= tmp && tmp <= 90){//대문자
            tmp = (tmp-'A'+13)%26 + 65;
            cout << tmp;
        }
        else cout << tmp;
    }
}