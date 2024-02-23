#include<iostream>
using namespace std;
int N, M;
int rect[5][5];
int bit_rect[5][5] = {0,};  //1이면 가로로 잇고, 0이면 세로로 잇기
int max_sum = -1;
void calcul(int low, int col);
void make_sum();
int main(){
    cin >> N >> M;
    string str;
    for(int i=1; i<=N; i++){
        cin >> str;
        for(int j=1; j<=M; j++){
            rect[i][j] = str[j-1] - '0';
        }
    }
    calcul(1,1);
    cout << max_sum;
}
void calcul(int low, int col){ //low, col를 계산해야 한다.
    if(low > N){
        //블록 계산
        make_sum();
        return;
    }
    //한 low 다 봄
    if(col > M){
        calcul(low+1,1);
        return;
    }
    bit_rect[low][col] = 1;
    calcul(low, col+1);
    bit_rect[low][col] = 0;
    calcul(low, col+1);
}
void make_sum(){
    int visited[5][5] = {0,};
    int tmp = 0;
    int block,l,c;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){ //시작점 고르기
            l = i;
            c = j;
            block = 0;
            if(!visited[l][c]){
                block = rect[l][c];
                visited[l][c]++;
                if(bit_rect[l][c]){ //가로
                    while(c < M){
                        c++;
                        if(visited[l][c]) break;
                        if(!bit_rect[l][c]) break;
                        block *= 10;
                        block += rect[l][c];
                        visited[l][c]++;
                    }
                }
                else{ // 세로
                    while(l < N){
                        l++;
                        if(visited[l][c]) break;
                        if(bit_rect[l][c]) break;
                        block *= 10;
                        block += rect[l][c];
                        visited[l][c]++;
                    }
                }
                tmp += block;
            }
        }
    }
    max_sum = max(tmp, max_sum);
}