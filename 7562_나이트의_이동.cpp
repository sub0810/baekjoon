#include<iostream>
#include<queue>
using namespace std;
int K,I;
int chess[300][300]={0,}; //몇번째 날에 익었는지를 기록.
int addrow[8] = {-2,-2,-1,-1,1,1,2,2};
int addcol[8] = {1,-1,2,-2,2,-2,1,-1};
queue<pair<int,int>> q;

void go_for_destination(int start_r, int start_c, int end_r, int end_c){
    int now_r, now_c, next_r, next_c;

    chess[start_r][start_c] = 1;
    q.push(make_pair(start_r,start_c));
    
    while(!q.empty()){
        now_r = q.front().first;
        now_c = q.front().second;
        q.pop();
        if(now_r == end_r && now_c == end_c){
            cout << chess[now_r][now_c]-1 << "\n";
            break;
        }
        for(int i=0; i<8; i++){
            next_r = now_r + addrow[i];
            next_c = now_c + addcol[i];
            if(next_r <= -1 || next_c <= -1 || next_r >= I || next_c >= I) continue;
            if(chess[next_r][next_c] == 0){
                chess[next_r][next_c] = chess[now_r][now_c] + 1;
                q.push(make_pair(next_r,next_c));
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int start_r, start_c, end_r, end_c;
    cin >> K;
    for(int i=0; i<K; i++){
        cin >> I;
        cin >> start_r >> start_c;
        cin >> end_r >> end_c;

        go_for_destination(start_r, start_c, end_r, end_c);

        //초기화
        while(!q.empty()) q.pop();
        for(int i=0; i<I; i++){
            for(int j=0; j<I; j++){
                chess[i][j] = 0;
            }
        }
    }
}