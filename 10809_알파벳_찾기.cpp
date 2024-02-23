#include<iostream>
using namespace std;
int main(){
    int alphabet_cnt[26];
    std::fill_n(alphabet_cnt, 26, -1);
    string in;

    getline(cin,in);
    for(int i=0; i<in.size(); i++){
        if(alphabet_cnt[in[i]-'a'] == -1) alphabet_cnt[in[i]-'a'] = i;
    }
    for(int j=0; j<26; j++) cout << alphabet_cnt[j] << " ";
}