#include<iostream>
using namespace std;
int min_gap = 1e9;
int N;
int ability[21][21];
void is_it_min(int select[]){
    int start = 0;
    int link = 0;
    for(int i = N; i > 1; i--){
        for(int j = i - 1; j > 0; j--){
            if(select[i] && select[j])
                start += ability[i][j] + ability[j][i];
            else if(!select[i] && !select[j])
                link += ability[i][j] + ability[j][i];
        }
    }
    //cout << "link : " << link << " start : " << start << endl;
    start = (start > link) ? start-link : link-start;
    min_gap = min(min_gap, start);
}

void DFS(int select[], int idx, int cnt, int n, int k){
    if(cnt == k){
        is_it_min(select);
        return;
    }
    
    for(int i = idx; i <= n; i++){
        if(select[i] == 1) continue;
        select[i] = 1;
        DFS(select, i, cnt + 1, n, k);
        select[i] = 0;
    }
}
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> ability[i][j];
        }
    }
    int select[21] = {0,};
    DFS(select, 1, 0, N, N/2);
    cout << min_gap;
}