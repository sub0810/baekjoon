#include<iostream>
#include<queue>
using namespace std;
int addrow[4] = {-1,0,1,0};
int addcol[4] = {0,1,0,-1};
int arr[100][100];
int visited[100][100] = {0,};
int d[100][100] = {0,};
int M,N; //M이 너비(가로), N이 높이(세로)
queue<pair<int,int>> q;
void BFS(int row, int col){
    int now_r, now_c, next_r, next_c;
    
    visited[row][col]++;
    d[row][col] = 1;
    q.push(make_pair(row,col));
    while(!q.empty()){
        now_r = q.front().first;
        now_c = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            next_r = now_r + addrow[i];
            next_c = now_c + addcol[i];
            if(next_r == -1 || next_c == -1 || next_r == N || next_c == M) continue;
            if(!visited[next_r][next_c] && arr[next_r][next_c]){
                visited[next_r][next_c]++;//돌아가지 못하게 visited로 막기
                d[next_r][next_c] = d[now_r][now_c]+1;
                q.push(make_pair(next_r,next_c));
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    string str;
    for(int i=0; i<N; i++){
        cin >> str;
        for(int j=0; j<M; j++){
            arr[i][j] = str[j]-'0';
        }
    }
    BFS(0,0);
    cout << d[N-1][M-1];
}