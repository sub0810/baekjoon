#include<iostream>
#include<queue>
using namespace std;
int N,M;
int tomato[1000][1000]; //몇번째 날에 익었는지를 기록.
int visited[1000][1000]={0,};
int addrow[4] = {-1,0,1,0};
int addcol[4] = {0,1,0,-1};
int all_ripe = 1;
queue<pair<int,int>> q;
void make_ripe(){
    int now_r, now_c, next_r, next_c;
    while(!q.empty()){
        now_r = q.front().first;
        now_c = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            next_r = now_r + addrow[i];
            next_c = now_c + addcol[i];
            if(next_r == -1 || next_c == -1 || next_r == N || next_c == M) continue;
            if(!visited[next_r][next_c] && tomato[next_r][next_c] == 0){
                visited[next_r][next_c]++;
                tomato[next_r][next_c] = tomato[now_r][now_c] + 1;
                q.push(make_pair(next_r,next_c));
            }
        }
    }
}
int main(){
    int date = -1;
    cin >> M >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> tomato[i][j];
            if(tomato[i][j] == 0) all_ripe = 0; // 0을 찾으면 다 익은게 아님
            //-1도 true이기 때문에, !-1은 false로 처리된다.
            if(tomato[i][j] == 1){
                q.push(make_pair(i,j));
            }
        }
    }

    if(all_ripe){
        cout << 0;
        exit(0);
    }
    make_ripe();
    //익는 과정이 끝났는데, 익지 않은 토마토 발견 -> -1 출력
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(tomato[i][j] == 0){
                cout << -1;
                exit(0);
            }
            date = max(date, tomato[i][j]);
        }
    }
    //다 익었으면, day 출력
    cout << date-1;
}