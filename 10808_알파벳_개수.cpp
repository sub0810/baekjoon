#include<iostream>
using namespace std;
int main(){
    int alphabet_cnt[26] = {0,};
    string in;
    getline(cin,in);
    for(int i=0; i<in.size(); i++){
        alphabet_cnt[in[i]-'a']++;
    }
    for(int j=0; j<26; j++) cout << alphabet_cnt[j] << " ";
}