#include<iostream>

using namespace std;

int main(){
    int index = 0;  //insert : 적고 -> 이동 / delete : 이동 -> 지우기
    int i;
    int cursor;
    string in = "";
    string inst;
    string nothing = "";
    int inst_num;
    char editor[600000];


    getline(cin, in);
    //입력받은 문자를 editor에 옮기기
    for(int i=0; i<in.size(); i++){
        editor[index++] = in[i];
    }
    cursor = index; //cursor가 적어야할 곳을 보고 
    //맨 왼쪽 : 0
    //맨 오른쪽 : index
    //동작
    cin >> inst_num;
    cin.ignore();
    while(inst_num--){
        getline(cin,inst);
        if(inst[0] == 'L'){
            if(cursor == 0) cursor=0;   //커서가 맨 앞이면 무시
            else cursor--;
        }
        else if(inst[0] == 'D'){
            if(cursor == index) cursor=index;   //커서가 맨 뒤면 무시
            else cursor++;
        }
        else if(inst[0] == 'B'){
            if(cursor == 0) cursor=0;   //커서가 맨 앞이면 무시
            else{
                for(i = cursor; i<index; i++){
                    editor[i-1]=editor[i];
                }
                editor[index--]=nothing[0]; //내용 비워주면서 index 줄이기
                cursor--;
            }
        }
        else if(inst[0] == 'P'){    //값 넣기
            //inst[2]에 있는 값 사용.
            for(i=index; i>cursor; i--){
                editor[i] = editor[i-1];
            }
            index++;
            editor[cursor++]=inst[2];
        }
        //cout << "checkpoint : ";
        //cout << editor;
        //cout << endl << "cursor : " << cursor << endl;
        //cout << "index : " << index << endl;
    }
    cout << editor;
}