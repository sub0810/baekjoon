#include<iostream>
using namespace std;
int N,M;
char arr[50][50];
    if(right == 0 && down == 0 && left == 0 && up == 0){
        cout << "Yes";
        exit(0);
    }
    else if(right){
        for(int j=col+1; j<M; j++){
            if(arr[row][j] == now) go_where(row,j,now,0,1,0,0);
        }
    }
    else if(down){
        for(int i=row+1; i<N; i++){
            if(arr[i][col] == now) go_where(i,col,now,0,0,1,0);
        }
    }
    else if(left){
        for(int j=col-1; j>-1; j--){
            if(arr[row][j] == now) go_where(row,j,now,0,0,0,1);
        }
    }
    else if(up){
        for(int i=row-1; i>-1; i--){
            if(arr[i][col] == now) go_where(i,col,now,0,0,0,0);
        }
    }
}
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; i++){ //row
        for(int j=0; j<M; j++){ //col
            go_where(i,j,arr[i][j],1,0,0,0);
        }
    }  

    cout << "No";
}