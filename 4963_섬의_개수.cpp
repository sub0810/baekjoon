#include<iostream>
using namespace std;
int arr[50][50];
int visited[50][50]={0,};
int addrow[8] = {1,0,-1,0,1,1,-1,-1};
int addcol[8] = {0,1,0,-1,1,-1,1,-1};
int w,h;
int cnt;
void check(int row, int col);
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    while(1){
        cin >> w >> h;
        if(w == 0 && h == 0) exit(0);

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> arr[i][j];
            }
        }
        cnt = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(!visited[i][j]){
                    visited[i][j]++;
                    if(arr[i][j]){
                        cnt++;
                        check(i,j);
                    }
                }
            }
        }
        cout << cnt << "\n";
        //초기화
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                visited[i][j] = 0;
            }
        }
    }
    
}
void check(int row, int col){
    int next_r, next_c;
    for(int i=0; i<8; i++){
        next_r = row + addrow[i];
        next_c = col + addcol[i];
        if(next_r == -1 || next_c == -1 || next_r == h || next_c == w) continue;
        if(!visited[next_r][next_c]){
            visited[next_r][next_c]++;
            if(arr[next_r][next_c]){
                check(next_r, next_c);
            }
        }
    }
}