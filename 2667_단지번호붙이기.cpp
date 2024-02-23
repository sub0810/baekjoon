#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int arr[25][25];
int visited[25][25]={0,};
int addrow[4] = {1,0,-1,0};
int addcol[4] = {0,1,0,-1};
int N;
int cnt;
void check(int row, int col);
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    string str;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> str;
        for(int j=0; j<N; j++){
            arr[i][j] = str[j]-'0';
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j]){
                visited[i][j]++;
                if(arr[i][j]){
                    cnt = 1;
                    check(i,j);
                    v.push_back(cnt);
                }
            }
        }
    }
    cout << v.size() << "\n";
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
    }
}
void check(int row, int col){
    int next_r, next_c;
    for(int i=0; i<4; i++){
        next_r = row + addrow[i];
        next_c = col + addcol[i];
        if(next_r == -1 || next_c == -1 || next_r == N || next_c == N) continue;
        if(!visited[next_r][next_c]){
            visited[next_r][next_c]++;
            if(arr[next_r][next_c]){
                cnt++;
                check(next_r, next_c);
            }
        }
    }
}