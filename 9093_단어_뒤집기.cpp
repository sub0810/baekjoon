#include<iostream>
#include<cstring>

using namespace std;

int main(){
    int inst_num;

    char temp[21];
    int i,j;
    int index = -1;
    
    cin >> inst_num;
    cin.ignore();
    while(inst_num--){
        string in = "";
        getline(cin, in);
        in += " ";
        index = -1;
        for(i=0; i<in.size(); i++){
            if(in[i] == ' '){
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
        cout << endl;
    }
}