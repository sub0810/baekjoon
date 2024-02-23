#include<iostream>
#include<vector>
using namespace std;
vector<int> v[1001];
int visited[1001] = {0,};
int N, M;
int CC = 0;
void DFS(int p){
    visited[p] = 1;
    for(int i=0; i<v[p].size(); i++){
        if(!visited[v[p][i]]) DFS(v[p][i]);
    }
}
int main(){
    int p1, p2;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> p1 >> p2;
        v[p1].push_back(p2);
        v[p2].push_back(p1);
    }

    for(int i=1; i<=N; i++){
        if(!visited[i]){
            CC++;
            DFS(i);
        }
    }
    cout << CC;
}
