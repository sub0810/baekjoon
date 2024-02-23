#include<iostream>
#include<string>
using namespace std;

int main(){
    int size;
    string in; getline(cin, in); size=in.size();
    string arr[1000];
    string tmp;

    for(int i=size-1; i>=0; i--){//짧은 길이부터 쭉 넣기
        arr[i]=in.substr(i);
    }
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(arr[i].compare(arr[j]) < 0){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    
    for(int i=0; i<size; i++) cout << arr[i] << endl;
}