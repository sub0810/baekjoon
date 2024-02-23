#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int L, C;
char input_char[15];
int check(string &pw);
void guess(int where, string pw);
int main(){
    string pw = "";
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> L >> C;
    for(int i=0; i<C; i++) cin >> input_char[i];
    sort(input_char,input_char+C);
    guess(0,pw);
}
int check(string &pw){
    int ja = 0;
    int mo = 0;
    for(int i=0; i<pw.length(); i++){
        if(pw[i] == 'a' || pw[i] == 'i' || pw[i] == 'e' || pw[i] == 'o' || pw[i] == 'u')
            mo++;
        else ja++;
    }
    return (mo > 0 && ja > 1);
}
void guess(int where, string pw){
    if(pw.length() == L){
        if(check(pw)){
            cout << pw << "\n";
        }
        //cout << "mo: " << mo << " ja: " << len-mo << "\n";
        return;
    }
    if(where >= C) return;
    guess(where+1, pw+input_char[where]);
    guess(where+1, pw);
}